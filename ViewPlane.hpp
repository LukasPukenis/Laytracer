//
//  ViewPlane.hpp
//  Laytracer
//
//  Created by Lukas on 12/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef ViewPlane_hpp
#define ViewPlane_hpp

class ViewPlane {
public:
  int hres;
  int vres;
  float s;
  float gamma;
  float inv_gamma;
};

#endif /* ViewPlane_hpp */
