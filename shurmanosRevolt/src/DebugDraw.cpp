#include "DebugDraw.h"
#include <cmath>
#include "Utils.h"

using namespace std;

DebugDraw::DebugDraw(RenderWindow* window) : b2Draw() {
    this->window = window;
    this->SetFlags(0xFFFFFFFF); //TODO dirty?
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    ConvexShape convex;
    convex.setPointCount(4);
    for(int i = 0; i < 4; ++i) 
        convex.setPoint(i, Utils::metersToPixels(vertices[i]));
    convex.setFillColor(Color(200,20,20,25));
    convex.setOutlineColor(Color::Red);
    convex.setOutlineThickness(2);
    window->draw(convex);
}

void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
}

void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
    CircleShape circle(Utils::metersToPixels(radius));
    circle.setPosition(Utils::metersToPixels(center));
    circle.setFillColor(Color(200,20,20,25));
    circle.setOutlineColor(Color::Red);
    circle.setOutlineThickness(2);
    window->draw(circle);
}

void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
}

void DebugDraw::DrawTransform(const b2Transform& xf) {
}

