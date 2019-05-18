# SDLplus_plus
SDL library wrapped in modern c++

Example usage:

//create window<br/>
SDL::Window window(true);

//fill it red<br/>
window.fillRect(255, 0, 0);

//draw bitmap on it<br/>
SDL::Surface surface("Images\\home.bmp");
window.blit(&surface);
