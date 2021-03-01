/*
 *  control.h
 *
 *  Created by Christian Wolfsteiner and modified by Patrick Jenny on 12/20/05.
 *
 */

#ifndef _CONTROL_H
#define _CONTROL_H

#include <map>
#include <string>

using namespace std;

/**
 * \brief Map that holds the contents of a control file.
 *
 * In its present form, the control class is a simple map that holds
 * the contents of the control file. The contents can be accessed as bools,
 * integers, doubles or strings with string keys that are identical to the
 * original keywords used in the file.
 *
 * In addition to storing the control file data the control class allocates
 * already all strategies used in the simulation. This follows an earlier
 * design decision which was to separate the strategy from the rest of the
 * simulation code: new strategies are easily implemented at a single place
 * (this file here) and can be readily used anywhere without headaches of
 * passing it down. Strategies can be accessed as void* via the getPointer(key)
 * method. The void* requires a correct cast at the time of use.
 *
 * A single control object is then passed to the simulator upon construction
 * and stored there. Hence, it is virtually accessible anywhere in the simulator.
 * While the access time of a map (via string keys) is efficient, most receiving
 * objects will still make local copies of the data to member variables, unless
 * a data is used only infrequent, in which case it does not need to have a class
 * analogy in form of a member variable.
 *
 *  Summary:
 *  - control object provides original control file data virtually anywhere
 *    in the code
 *  - access with string keys that are the same as used in the control file
 *  - no hassle with passing down meter long interface lists
 *  - easy addition of new parameters
 *  - control class much shorter now, virtually no class variables (only a map)
 *  - control class can be re-read any time via read(), i.e., monitor changes
 *  - stand alone strategy allocation;
 *  - elegant grouping of strategy possible (e.g., factory together with output)
 *  - note: be careful with the right type casts with getPointer()
 *
 */
class Control {
public:
  Control          ();
  Control          (string ctrlFile);
  ~Control         ();
  void   read      ();
  bool   exists    (string key);
  int    getInt    (string key, int tok = 0);
  bool   getBool   (string key, int tok = 0);
  double getDouble (string key, int tok = 0);
  string getString (string key, int tok = 0);
  static void   findKey     (istream& istr, string key);
  static bool   openFile    (ifstream& file, string name, string key);
  static double readWithUnit(const char *timestr);
protected:
  void   addEntry  (string key, string val, void* ptr = NULL);
  void   addPointer(string key, void* ptr, string val = "");
  string getToken  (string key, int tok = 0);
  struct ControlPair {
    string _val;
    void*  _ptr;
  };
  map<string,ControlPair> _ctrl;
  string                  _file;
};

#endif

