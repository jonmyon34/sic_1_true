#include "all.h"

void ui::Draw()
{
	DrawGraph(0, GAUGEPOS_Y, ui_gh, true);
	DrawGraph(0, 0, ui_gh2, true);
}

void ui::View()
{

}

void ui::All()
{
	Draw();
}