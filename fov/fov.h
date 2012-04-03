struct Point {
	float x;
	float y;
};

struct Triangle {
	Point t1;
	Point t2;
	Point t3;
};

void checkInsection(Triangle fov, Triangle* triangles, int ctriangles, float (*callback)(void* obj, Triangle* triangle), void* obj);
