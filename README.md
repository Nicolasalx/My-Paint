# my_paint

Usage :

You can run launch my_paint using the ./my_paint command or,
if you want to directly edit an image, you can directly launch my_paint with an image pass : ./my_paint my_image.png
(You can import image of different type : bmp, png, tga, jpg, gif, psd, hdr and pic)

## Must :

• Window that you can minimize, enlarge and close ✅

- You can minimize and enlarge the window, the position of the image that you are currently editing will be dynamically calculated,
By default, when you resize the window in csfml, the scale of what it is displayed change,
but in our program, the field of view is enlarged when you enlarge the size of the window and the same when you minimize the window

--------------------

• Provide at least the pencil and eraser tools ✅

- You can select the pencil tool in the toolbar of our program (the bar on the left), same thing for the eraser.
You can change the color of the pencil, and other tool by clicking on the chromatic wheel or by choosing a color in the color palette
You can change the size of the pencil, and other tool with the slider on the bottom left of the window
The eraser subtract color from the paper by using different blend mode,
so when you erase something on the default white paper and you see gray,
the eraser doesn't draw gray, but have suppressed the existing color from the paper,
you can verify this by exporting the image in png (we are going to see later how to export image)

--------------------

• Buttons must have different states (at least 3 : HOVER, PRESSED and CLICKED for example) ✅

- There is multiple button, with different state, for example, the undo and redo button have those state :
Disable, Hovered, Pressed, Released with a pressed effect where the button moves a bit.

--------------------

• A menu bar, with at least the file, edit, and help features. Each item must be a drop-down menu. ✅
  • In the file item, the options new file, open file, save file. ✅
  • In the edition item, the selection of the pencil and eraser tools ✅
  • In the help item, the options about (which must display your login), and help (which explains how to use the software) ✅

- We have all those categories, there are display in the top bar of our software, you can click on those button to see what appen.

--------------------

• A new side-menu (tool bar) poping up upon tool selection which allows you modify it : ✅
  • For pencil : change the line thickness ✅
  • For eraser : change the shape (circle or square) and its size ✅

- You can change the pencil and eraser thickness with the botton left slider.
You can change the shape that is drawn with the pencil and the eraser by selecting the tool that you want to change property,
and after click on "Edit" and "Draw cicle", "Draw rectangle" or "Draw brush" to cahnge the mode of the selected tool.

--------------------

• Be able to make a drawing with the tools using the mouse ✅

- You can select a tool and draw on the paper by clicking on the left button of your mouse.

--------------------

• Save the image (.jpg format by default) ✅

- You can save your beautiful drawing by clicking on "File", "Save image",
entering the name you want to give to your drawing and select the format of exportation and then save the image.

--------------------

## Should :

• User must can enter file name in terminal or in a new window poping up when chosing an option in file menu drop down ✅

- You can do both option to import image in the software, ./my_paint my_image.png or
after had launched the program select "File", "Import image" and then select the image you want to import.

--------------------

• Layer management ✅

- In the bottom right there is a dedicated part to layer management where you can :
Create a new layer by clicking on the "plus" button,
Select a layer by clicking on it, the selected layer is in blue,
Hide a layer by clicking on the "eye" button,
Move a layer up, by clicking on the "up arrow" button, so the layer will be on top of each other
Move a layer down, by clicking on the "down arrow" button, so the layer will be on the bottom of each other
Browse layer by pressing the up arrow button and down arrow button of your keyboard
Delete a layer by clicking on the trash bin button.

--------------------

• A side menu with the color palette for the pencil tool ✅

- You can select the color you want for the tool you want on the chromatic wheel and
color palette in the color selection section on the top right

--------------------

• Save the image in other formats (.bmp and .png) ✅

- As said in the Must section, you can save your drawing in 3 different formats : PNG, JPG and BMP

--------------------

• Add basic shapes (circle, rectangle) ❌

- Our software doesn't provide the possibility to create simple shape.

--------------------

• Possibility to zoom on the image ✅

- You can zoom on your drawing by moving the slider on the top bar, you can : Zoom in and Zoom out
The zoom is applied to the center of the part you're currently looking.

- You can select the hand tool in the toolbar and move the paper to see a specific part of you drawing (this is a bonus)

--------------------

• Add the selection tool (with a rectangle shape) ❌

- Our software doesn't provide the possibility to select something.

--------------------

• Add the cut/copy/paste options in the edition menu, usable on a part of the image previously selected
with the selection tool, AND the paste to another place of the image, or on another layer. ❌

- Our software doesn't provide the possibility to cut/copy/past something.

--------------------

## Could

• Layer mask management ✅

- You can create a layer that is a mask, draw on it and put it on each other to act as mask of another layer,
You can change layer position by using the up arrow button and the down arrow button.

--------------------

• Image import ✅

- As said in the should section you can import image by selecting "File", "Import image" and then select the image you want to import.

--------------------

• Management of brush for the pencil and eraser tools ✅

- You can select the brush tool for pencil in the toolbar, by clicking on the brush icon,
or by selecting the pencil and click in the "Edit" button, and selecting "Draw brush".
Same thing for the eraser, select the eraser and click in the "Edit" button, and select "Draw brush".
 
--------------------

• Add complex shapes (convex) ❌

- Our software doesn't provide the possibility to create complex shape.

--------------------

• Management of transformations (translation, rotation) of entities ❌

- Our software doesn't provide the possibility to do transformation on entities.

--------------------

• Add undo and redo operation in edition menu ✅

- You can undo and redo what you have draw by clicking on the left arrow to undo something and the right arrow to redo something.
(each layer has its own undo redo information,
so if you create a new layer draw on it,
and after you want to undo something that you have done on the layer below, you can)
