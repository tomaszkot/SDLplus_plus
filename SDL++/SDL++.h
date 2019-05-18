// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SDL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SDL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SDL_EXPORTS
#define SDL_API __declspec(dllexport)
#else
#define SDL_API __declspec(dllimport)
#endif

//// This class is exported from the SDL++.dll
//class SDL_API CSDL {
//public:
//	CSDL(void);
//	// TODO: add your methods here.
//};
//
//extern SDL_API int nSDL;
//
//SDL_API int fnSDL(void);
