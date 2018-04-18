#include "htmlGraphics.h"

FILE *graphicsFilePtr;

/// @brief Open a graphics (html) file to write to.
///
/// Begin the process of creating graphics by opening an html
/// file and writing the first few lines to it. This function
/// MUST be called successfully before calling any of the other
/// graphics functions. It needs to be called only once per
/// drawing.
///
/// @param width width of the graphics window (pixels)
/// @param height height of the graphics window (pixels)
///
/// @return 0 if successful, 1 if failed
///
int graphicsOpen(int width, int height) {

    graphicsFilePtr = fopen(GRAPHICS_FILE_NAME, "w");
    if(graphicsFilePtr == NULL){
        printf(GRAPHICS_FILE_NAME);
        printf(" could not be opened! Can not create drawing output file!\n");
        return 1;
    }
    // printf("creating drawing...\n");
    fprintf(graphicsFilePtr, "<!DOCTYPE html>\n<html>\n<body>\n\n");
    fprintf(graphicsFilePtr, "<canvas id=\"myCanvas\" width=\"%d\" height=\"%d\" style=\"border:1px solid #d3d3d3;\">\n", width, height);
    fprintf(graphicsFilePtr, "Your browser does not support the HTML5 canvas tag.</canvas>\n\n");
    fprintf(graphicsFilePtr, "<script>\n\n");
    fprintf(graphicsFilePtr, "var c = document.getElementById(\"myCanvas\");\n");
    fprintf(graphicsFilePtr, "var ctx = c.getContext(\"2d\");\n");
    fprintf(graphicsFilePtr, "mainFunction();\n\nfunction mainFunction(){\n\n");
    return 0;
}


/// @brief Complete and close graphics (html) file to write to.
///
/// Conclude the process of creating graphics by writing the
/// required graphics definitions and closing the file. This
/// function MUST be called after all of the other drawing
/// functions. It needs to be called only once per drawing.
///
/// @return Void
///
void graphicsUpdate(void){

    // close main function
    fprintf(graphicsFilePtr, "}\n\n");

    // pixel function
    fprintf(graphicsFilePtr, "function graphicsPixel(x, y, red, green, blue){\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.moveTo(x, y);\n");
	fprintf(graphicsFilePtr, "\tctx.lineTo(x+1, y+1);\n");
	fprintf(graphicsFilePtr, "\tctx.strokeStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.stroke();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // line function
    fprintf(graphicsFilePtr, "function graphicsLine(x1, y1, x2, y2, red, green, blue){\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.moveTo(x1, y1);\n");
	fprintf(graphicsFilePtr, "\tctx.lineTo(x2, y2);\n");
	fprintf(graphicsFilePtr, "\tctx.strokeStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.stroke();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // rectangle function
    fprintf(graphicsFilePtr, "function graphicsRectangle(x, y, width, height, red, green, blue){\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.rect(x, y, width, height);\n");
	fprintf(graphicsFilePtr, "\tctx.strokeStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.stroke();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // rectangle filled function
    fprintf(graphicsFilePtr, "function graphicsRectangleFilled(x, y, width, height, red, green, blue){\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.rect(x, y, width, height);\n");
	fprintf(graphicsFilePtr, "\tctx.fillStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.fill();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // circle function
    fprintf(graphicsFilePtr, "function graphicsCircle(x, y, radius, red, green, blue) {\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.arc(x, y, radius, 0, 2*Math.PI);\n");
	fprintf(graphicsFilePtr, "\tctx.strokeStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.stroke();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // circle filled function
    fprintf(graphicsFilePtr, "function graphicsCircleFilled(x, y, radius, red, green, blue) {\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.arc(x, y, radius, 0, 2*Math.PI);\n");
	fprintf(graphicsFilePtr, "\tctx.fillStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.fill();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // ellipse function
    fprintf(graphicsFilePtr, "function graphicsEllipse(x, y, width, height, red, green, blue) {\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.moveTo(x-width/2, y);\n");
	fprintf(graphicsFilePtr, "\tctx.bezierCurveTo(x-width/2, y-height/2, x+width/2, y-height/2, x+width/2, y);\n");
	fprintf(graphicsFilePtr, "\tctx.bezierCurveTo(x+width/2, y+height/2, x-width/2, y+height/2, x-width/2, y);\n");
	fprintf(graphicsFilePtr, "\tctx.strokeStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.stroke();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // ellipse filled function
    fprintf(graphicsFilePtr, "function graphicsEllipseFilled(x, y, width, height, red, green, blue) {\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.moveTo(x-width/2, y);\n");
	fprintf(graphicsFilePtr, "\tctx.bezierCurveTo(x-width/2, y-height/2, x+width/2, y-height/2, x+width/2, y);\n");
	fprintf(graphicsFilePtr, "\tctx.bezierCurveTo(x+width/2, y+height/2, x-width/2, y+height/2, x-width/2, y);\n");
	fprintf(graphicsFilePtr, "\tctx.fillStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.fill();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // triangle function
    fprintf(graphicsFilePtr, "function graphicsTriangle(x1, y1, x2, y2, x3, y3, red, green, blue) {\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.moveTo(x1, y1);\n");
	fprintf(graphicsFilePtr, "\tctx.lineTo(x2, y2);\n");
	fprintf(graphicsFilePtr, "\tctx.lineTo(x3, y3);\n");
	fprintf(graphicsFilePtr, "\tctx.lineTo(x1, y1);\n");
	fprintf(graphicsFilePtr, "\tctx.strokeStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.stroke();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // triangle function filled
    fprintf(graphicsFilePtr, "function graphicsTriangleFilled(x1, y1, x2, y2, x3, y3, red, green, blue) {\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.moveTo(x1, y1);\n");
	fprintf(graphicsFilePtr, "\tctx.lineTo(x2, y2);\n");
	fprintf(graphicsFilePtr, "\tctx.lineTo(x3, y3);\n");
	fprintf(graphicsFilePtr, "\tctx.lineTo(x1, y1);\n");
	fprintf(graphicsFilePtr, "\tctx.fillStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.fill();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // draw text function
    fprintf(graphicsFilePtr, "function graphicsPrintString(textString, x, y, textSize, red, green, blue){\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.font = textSize + \"px Arial\";\n");
	fprintf(graphicsFilePtr, "\tctx.fillStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.fillText(textString, x, y);\n");
	fprintf(graphicsFilePtr, "\tctx.fill();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // draw integer function
    fprintf(graphicsFilePtr, "function graphicsPrintInt(number, x, y, textSize, red, green, blue){\n\n");
	fprintf(graphicsFilePtr, "\tctx.beginPath();\n");
	fprintf(graphicsFilePtr, "\tctx.font = textSize + \"px Arial\";\n");
	fprintf(graphicsFilePtr, "\tctx.fillStyle = \"rgb(\" + red + \",\" + green + \",\" + blue + \")\";\n");
	fprintf(graphicsFilePtr, "\tctx.fillText(number.toString(), x, y);\n");
	fprintf(graphicsFilePtr, "\tctx.fill();\n");
	fprintf(graphicsFilePtr, "\tctx.closePath();\n");
    fprintf(graphicsFilePtr, "}\n\n");

    // end and close file
    fprintf(graphicsFilePtr, "</script>\n\n</body>\n</html>\n");
    fclose(graphicsFilePtr);

    // printf("...done!\n");

}


/// @brief Draw a pixel.
///
/// @param x x-coordinate (pixels)
/// @param y y-coordinate (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsPixel(int x, int y, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsPixel(%d, %d, %d, %d, %d);\n", x, y, red, green, blue);
}


/// @brief Draw a line.
///
/// @param x1 start point x-coordinate (pixels)
/// @param y1 start point y-coordinate (pixels)
/// @param x2 end point x-coordinate (pixels)
/// @param y2 end point y-coordinate (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsLine(int x1, int y1, int x2, int y2, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsLine(%d, %d, %d, %d, %d, %d, %d);\n", x1, y1, x2, y2, red, green, blue);
}


/// @brief Draw an empty rectangle.
///
/// @param x top left corner x-coordinate (pixels)
/// @param y top left corner y-coordinate (pixels)
/// @param width width of rectangle (pixels)
/// @param height height of rectangle (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsRectangle(int x, int y, int width, int height, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsRectangle(%d, %d, %d, %d, %d, %d, %d);\n", x, y, width, height, red, green, blue);
}


/// @brief Draw a filled rectangle.
///
/// @param x top left corner x-coordinate (pixels)
/// @param y top left corner y-coordinate (pixels)
/// @param width width of rectangle (pixels)
/// @param height height of rectangle (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsRectangleFilled(int x, int y, int width, int height, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsRectangleFilled(%d, %d, %d, %d, %d, %d, %d);\n", x, y, width, height, red, green, blue);
}


/// @brief Draw an empty circle.
///
/// @param x center x-coordinate (pixels)
/// @param y center y-coordinate (pixels)
/// @param radius radius of circle (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsCircle(int x, int y, int radius, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsCircle(%d, %d, %d, %d, %d, %d);\n", x, y, radius, red, green, blue);
}

/// @brief Draw a filled circle.
///
/// @param x center x-coordinate (pixels)
/// @param y center y-coordinate (pixels)
/// @param radius radius of circle (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsCircleFilled(int x, int y, int radius, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsCircleFilled(%d, %d, %d, %d, %d, %d);\n", x, y, radius, red, green, blue);
}


/// @brief Draw an empty ellipse.
///
/// @param x center x-coordinate (pixels)
/// @param y center y-coordinate (pixels)
/// @param width width of ellipse (pixels)
/// @param height height of ellipse (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsEllipse(int x, int y, int width, int height, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsEllipse(%d, %d, %d, %d, %d, %d, %d);\n", x, y, width, height, red, green, blue);
}


/// @brief Draw a filled ellipse.
///
/// @param x center x-coordinate (pixels)
/// @param y center y-coordinate (pixels)
/// @param width width of ellipse (pixels)
/// @param height height of ellipse (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsEllipseFilled(int x, int y, int width, int height, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsEllipseFilled(%d, %d, %d, %d, %d, %d, %d);\n", x, y, width, height, red, green, blue);
}


/// @brief Draw an empty triangle.
///
/// @param x1 first point x-coordinate (pixels)
/// @param y1 first point y-coordinate (pixels)
/// @param x2 second point x-coordinate (pixels)
/// @param y2 second point y-coordinate (pixels)
/// @param x3 third point x-coordinate (pixels)
/// @param y3 third point y-coordinate (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsTriangle(%d, %d, %d, %d, %d, %d, %d, %d, %d);\n", x1, y1, x2, y2, x3, y3, red, green, blue);
}


/// @brief Draw a filled triangle.
///
/// @param x1 first point x-coordinate (pixels)
/// @param y1 first point y-coordinate (pixels)
/// @param x2 second point x-coordinate (pixels)
/// @param y2 second point y-coordinate (pixels)
/// @param x3 third point x-coordinate (pixels)
/// @param y3 third point y-coordinate (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsTriangleFilled(%d, %d, %d, %d, %d, %d, %d, %d, %d);\n", x1, y1, x2, y2, x3, y3, red, green, blue);
}


/// @brief Draw text.
///
/// @param textString the text to draw
/// @param x bottom left, x-coordinate (pixels)
/// @param y bottom left, y-coordinate (pixels)
/// @param textSize of text (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsPrintString(char textString[], int x, int y, int textSize, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsPrintString(\"%s\", %d, %d, %d, %d, %d, %d);\n", textString, x, y, textSize, red, green, blue);
}


/// @brief Draw an integer number.
///
/// @param number the number to draw
/// @param x bottom left, x-coordinate (pixels)
/// @param y bottom left, y-coordinate (pixels)
/// @param textSize of text (pixels)
/// @param red red value, 0-255
/// @param green green value, 0-255
/// @param blue blue value, 0-255
///
/// @return Void
///
void graphicsPrintInt(int number, int x, int y, int textSize, int red, int green, int blue){
    fprintf(graphicsFilePtr, "\tgraphicsPrintInt(%d, %d, %d, %d, %d, %d, %d);\n", number, x, y, textSize, red, green, blue);
}


/// @brief Open the graphics file in the default web browser.
///
/// @return Void
///
void graphicsDisplay(void){
    system(GRAPHICS_DISPLAY_COMMAND);

}
