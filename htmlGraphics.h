/// @file htmlGraphics.h
///
/// @brief Library for drawing some common graphics objects.
///
/// This is a c library to output graphics. The graphics are
/// output in the form of an html file which can be viewed
/// within any web browser that supports HTML 5. The graphics
/// file can also be launched by the library. In this case
/// the graphics file will open up in the default browser.
///
/// Inspired by the KISS IDE graphics library. Adapted from
/// drawingV03.html.
///
/// References:
/// - HTML Canvas Reference
/// https://www.w3schools.com/graphics/canvas_intro.asp
/// - How to draw an ellipse or oval on HTML5 canvas?
/// http://www.williammalone.com/briefs/how-to-draw-ellipse-html5-canvas/
///
/// Created 28 Dec 2017
///
/// @author Mustafa Ghazi

#ifdef _cplusplus
extern "C" {
#endif

#ifndef HTMLGRAPHICS_H
#define HTMLGRAPHICS_H

#include <stdio.h>
#include <stdlib.h>

#define GRAPHICS_FILE_NAME "myDrawing.html"

#ifdef _WIN32
    #define GRAPHICS_DISPLAY_COMMAND "myDrawing.html"
#elif __linux__
    #define GRAPHICS_DISPLAY_COMMAND "sensible-browser myDrawing.html"
#elif __APPLE__
    #define GRAPHICS_DISPLAY_COMMAND "open myDrawing.html"
#else
    #define GRAPHICS_DISPLAY_COMMAND "myDrawing.html"
#endif

/// @brief Open a graphics (html) file to write to.
int graphicsOpen(int width, int height);

/// @brief Complete and close graphics (html) file to write to.
void graphicsUpdate();

/// @brief Draw a pixel.
void graphicsPixel(int x, int y, int red, int green, int blue);

/// @brief Draw a line.
void graphicsLine(int x1, int y1, int x2, int y2, int red, int green, int blue);

/// @brief Draw an empty rectangle.
void graphicsRectangle(int x, int y, int width, int height, int red, int green, int blue);

/// @brief Draw a filled rectangle.
void graphicsRectangleFilled(int x, int y, int width, int height, int red, int green, int blue);

/// @brief Draw an empty circle.
void graphicsCircle(int x, int y, int radius, int red, int green, int blue);

/// @brief Draw a filled circle.
void graphicsCircleFilled(int x, int y, int radius, int red, int green, int blue);

/// @brief Draw an empty ellipse.
void graphicsEllipse(int x, int y, int width, int height, int red, int green, int blue);

/// @brief Draw a filled ellipse.
void graphicsEllipseFilled(int x, int y, int width, int height, int red, int green, int blue);

/// @brief Draw an empty triangle.
void graphicsTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int red, int green, int blue);

/// @brief Draw a filled triangle.
void graphicsTriangleFilled(int x1, int y1, int x2, int y2, int x3, int y3, int red, int green, int blue);

/// @brief Draw text.
void graphicsPrintString(char textString[], int x, int y, int textSize, int red, int green, int blue);

/// @brief Draw an integer number.
void graphicsPrintInt(int number, int x, int y, int textSize, int red, int green, int blue);

/// @brief Open the graphics file in the default web browser.
void graphicsDisplay();

#endif

#ifdef _cplusplus
}
#endif

