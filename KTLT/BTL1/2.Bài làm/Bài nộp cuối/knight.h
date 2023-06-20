#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"


void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
float BaseDamage12345(int MaSK);
int Level(int ThuTuSuKien);
int convert_string_int(string s);
void cacsukien(string a, int(&ARR)[1024], int(&size));
void Used_File(string a, string(&File)[1024], int(&size));
void cutnumber(int n, int (&idNam)[1024], int (&NumNam));
bool songuyento(int n);
void Get_Seq(string a, int (&SEQ)[1024], int(&size));
bool CheckMountain(int (&arr)[1024], int socacso, int (&mtx), int (&mti));
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

#endif // __KNIGHT_H__ 