# SDLplus_plus
SDL library wrapped in modern c++

Example usage

//create window
SDL::Window window(true);

//fill it red
window.fillRect(255, 0, 0);

//draw bitmap on it
window.blitBMP("Images\\home.bmp");
