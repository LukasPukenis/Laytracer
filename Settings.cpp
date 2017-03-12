//
//  Settings.cpp
//  Laytracer
//
//  Created by Lukas on 14/12/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#define DEV true

#include "Settings.hpp"

#if DEV
  int Settings::AntiAliasLevel = 4;
  int Settings::Width = 300;
  int Settings::Height = 200;
#endif
#ifndef DEV
  int Settings::AntiAliasLevel = 4;
  int Settings::Width = 800;
  int Settings::Height = 600;
#endif
