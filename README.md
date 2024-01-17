# Half-Life Texture Modification Script
This program is built around taking exported textures from the .WAD files in Half-Life's /valve/ folder, and replacing them with a texture of the same size styled after the [magenta and black checkerboarded placeholder texture](https://static.wikia.nocookie.net/gmod/images/9/99/The_Missing_textures.png/) commonly used by software.

To use the program, you put the executable file in the same directory as the .BMP images from the WAD3 file, and a list.txt containing the names of each image separated by newlines (I used [Half-Life Texture Tools](https://developer.valvesoftware.com/wiki/Half-Life_Texture_Tools) to get these). You must also create a subdirectory called `new`. This is what your directory should look like, pictured with `spraypaint.wad`:

![image](https://github.com/rm-steele/HLTextureStyler/assets/152836752/2a980e13-fbb9-4959-b9e7-a6148f161422)

Once your directory is set up, run the program. The `new` folder will be filled with the modified images. Take these and compile them into a .WAD file once again. I did this using HLTT once again, but I believe the Half-Life SDK has a tool for this.
in your Half-Life install, place
