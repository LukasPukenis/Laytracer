//
//  main.cpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#define SDL_MAIN_HANDLED

#include "Settings.hpp"
#include <iostream>
#include <memory>

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glext.h>
	#include <SDL2/SDL.h>
#else
	#include <gl/glew.h>	
	#include <SDL.h>
#endif


#include "World.hpp"
#include "MultipleObjects.hpp"
#include "Plane.hpp"
#include "Light.hpp"
#include "PointLight.hpp"
#include "Recorder.h"
#include <sstream>
#include <string>

void handleKey(SDL_Event * event, int * quit) {
    if (event->type == SDL_KEYDOWN)
    {
        if (event->key.keysym.sym == SDLK_ESCAPE)
        {
            *quit = 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    } else {
        //Create window
      window = SDL_CreateWindow( "Laytracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Settings::Width, Settings::Height, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        } else {            
            SDL_Event event;
            int quit = 0;
          
            World w;
            MultipleObjects multiTracer(&w);
            w.setTracer(&multiTracer);
          
			// set up lights
			auto l1 = std::make_shared<PointLight>(Point3D(0.0, -500.0, 300.0), 10.0, RGBColor(0.0, 1.0, 0.0));
			w.addLight(l1.get());

            float radius = 60;

			std::vector<std::shared_ptr<Sphere>> spheres;

			auto p1 = std::make_shared<Plane>(Point3D(0, 1000, -1000), Point3D(0.0, 0, 0.2));
			p1->setColor(RGBColor(255, 255, 0));
			w.addObject(p1.get());

			const int CIRCLES = 3;
			const double dist = 150.0;

			for (auto i = 0; i < 1; i++) {
				for (auto j = 0; j < 1; j++) {
					for (auto n = 0; n < CIRCLES; n++) {
						auto sphere = std::make_shared<Sphere>();
						spheres.push_back(sphere);
						sphere->setPosition(
							Point3D((n - 1) * dist,
							0,
							0
						));

						auto r = 150.0f;
						auto g = (n+1) * 70.0;
						auto b = 100;

						sphere->setColor(RGBColor(r, g, b));
						sphere->setRadius(radius);
						w.addObject(sphere.get());
					}
				}
			}                      

			// add recorder
			Recorder rec;
			rec.setSDLSurface(SDL_GetWindowSurface(window));
						
			Action action1;
			action1.modifyNormal(0, 0, 0.01);
			action1.setObject(w.objects[0]);
			action1.setType(ACTION_TARGET_TYPE::PLANE);
			
			Action action2;
			action2.modifyPos(0, 10, 20);
			action2.setObject(w.lights[0]);
			action2.setType(ACTION_TARGET_TYPE::LIGHT);

			ActionTree actionTree;
			//actionTree.addAction(action1);
			actionTree.addAction(action2);

			w.build();
			
			std::ostringstream oss;
#ifdef __APPLE__
#else
			system("del ./tmp/ / F / Q");
#endif
			for (auto i = 0; i < 200; i++) {
				w.render_scene(window);
				actionTree.step();				
				oss << "tmp/image" << (i+1) << ".bmp";
				std::cout << "Rendering " << oss.str() << std::endl;
				SDL_SaveBMP(SDL_GetWindowSurface(window), oss.str().c_str());
				oss.str("");
			}  

#define REC_GIF
			system("make_gif.bat");
#ifdef REC_GIF
	#ifdef __APPLE__
	#else			
		
	#endif
#endif

            while (!quit) {
                while( SDL_PollEvent( &event ) != 0 ) {
                    //User requests quit
                    if( event.type == SDL_QUIT )
                    {
                        quit = true;
                    } else {
                      handleKey( &event, &quit);
                    }
                }
            }
            
            //Destroy window
            SDL_DestroyWindow( window );
            
            //Quit SDL subsystems
            SDL_Quit();
        }
    }
    
    return 0;
}
