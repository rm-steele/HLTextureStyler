# Half-Life Texture Stylization Script
This program is built around taking exported textures from the .WAD files in Half-Life's \valve\ folder and .VPK files in Half-Life 2's \hl2\ folder, and replacing them with a texture of the same size styled after the [magenta and black checkerboarded placeholder texture](https://static.wikia.nocookie.net/gmod/images/9/99/The_Missing_textures.png/) commonly used by software.

To use the program, you put the executable file in the same directory as the .BMP images from the WAD3 file, and a list.txt containing the names of each image separated by newlines (I used [Half-Life Texture Tools](https://developer.valvesoftware.com/wiki/Half-Life_Texture_Tools) to get these). You must also create a subdirectory called `new`. This is what your directory should look like, pictured with `spraypaint.wad`:

![image](https://github.com/rm-steele/HLTextureStyler/assets/152836752/2a980e13-fbb9-4959-b9e7-a6148f161422)

Once your directory is set up, run the program. The `new` folder will be filled with the modified images. Take these and compile them into a .WAD file once again. I did this using HLTT once again, but I believe the Half-Life SDK has a tool for this.

## HL2 setup (and probably other Source games if you modify the instructions some)

You'll need 4 programs.
- GCFScape
- vtex2
- VTFEdit/VTFEdit Reloaded
- HL2TextureStyler, either compiled by you or from the releases tab.

1) Open `Half-Life 2\hl2\hl2_textures_dir.vpk` in GCFScape and expand the root folder. Right click and extract materials to an empty directory. 
2) Open that directory in command prompt and input the following: `vtex2 extract -f bmp -r .\materials\`. Make sure vtex2 is in the same folder as your materials folder or in a PATH environment variable folder. Keep that command window open.
3) Go into the materials folder and run this command in command prompt: `del /F /S /Q *.v??`, then run `dir /B /S /A:-D > list.txt`. One more time, keep cmd open.
4) Move list.txt into the same folder as HL2TS. Make sure the entry for list.txt is the first entry in the file.
5) Copy the `materials` folder somewhere else, rename it `materials_new`, and move it into the same directory as the original materials folder
6) Navigate to `materials_new` with CMD and run `del /F /S /Q *.bmp`, then run HL2TS.
7) If `materials_new` is filled with blocky textures, then open VTFEdit and go to Tools > Convert Folder. Set your input folder as `materials_new` and your output folder as whatever you want. Select "To VTF" and change the text in the box to be *.bmp. Check Recursive, uncheck Create VMT Files. Click Options and go to Advanced, then set the version to 7.1. Hit Convert. The program is likely to freeze, just give it some time.
8) Go into your Half-Life 2 files and open the folder `\hl2\`. Create a new folder called `custom` and put your output folder in there. The folder layout should be `Half-Life 2\hl2\custom\<your folder name>\materials\`

You should now have modified textures.
