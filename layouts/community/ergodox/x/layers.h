#ifndef LAYERS_X_H
#define LAYERS_X_H

#define curLayer (biton32(layer_state))

enum Layer
{
	Base = 0,
	Symbol,
	Numpad,
	Function
};

#endif

