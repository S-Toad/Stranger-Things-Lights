// Color.h

#ifndef _COLOR_h
#define _COLOR_h

class Color {
public:
	Color(int r, int g, int b);
	virtual ~Color();

	int R;
	int G;
	int B;
};

#endif /* _COLOR_H_ */