#include "stdafx.h"
#include <stdio.h>
using namespace std;

bool BitEncendido(int Simbolo, int cual)
{
	int Mascara = 1;
    
	Mascara = Mascara << cual;
	if ((Simbolo & Mascara)==0)
		return false;    // Da 0 lo que significa que la posicion cual estaba en 0
	else return true;	// Da <>0 lo que significa que la posicion cual estaba en 1
    
}

bool BitApagado(int Simbolo, int cual)
{
	int Mascara = 1;
    
	Mascara = Mascara << cual;
	if ((Simbolo & Mascara)==0)
		return true; // Da 0 lo que significa que la posicion cual estaba en 0
	else return false;	// Da <>0 lo que significa que la posicion cual estaba en 1
    
}

void EncenderBit(int &Simbolo, int cual)
{
	int Mascara = 1;
    
	Mascara = Mascara << cual;
	Simbolo = Simbolo | Mascara;
}


void ApagarBit(int &Simbolo, int cual)
{
	int Mascara = 1;
    
	Mascara = Mascara << cual;
	Mascara = ~Mascara;
	Simbolo = Simbolo & Mascara;
}

void PinteBits(int Simbolo)
{
	int Uno=1; 
	int Cero=0;
	for (int i=7; i>=0; --i)
	{
		if (BitEncendido(Simbolo,i))
			printf("%d ",Uno);
		else
			printf("%d ",Cero);
	}
    
	printf("\n");
}
void InvertirTbits(int &Simbolo, int cual)
{
	int Mascara = 1;

	Mascara = Mascara << cual;
	Simbolo = Simbolo ^ Mascara;
}
int main(int argc, char* argv[])
{
	int Prueba=0;
	int j;
    
	for(j=0; j<=7; j++)
	{
		printf("%s \n", "------------------"); 
		EncenderBit(Prueba,j);       // Enciende el Bit en la posicion "j"
		printf("%d :", Prueba); PinteBits(Prueba);
		ApagarBit(Prueba,j);		// Apaga el Bit en la posicion "j"
		printf("%d :", Prueba); PinteBits(Prueba);//Queda en 0 porque apago el Bit encendido.
	}
    
    for (j=0; j<=255; j++)
	{
		printf("Numero %d : ", j);
		PinteBits(j);
	}
	return 0;
}



/*------------------
1 :0 0 0 0 0 0 0 1
0 :0 0 0 0 0 0 0 0
------------------
2 :0 0 0 0 0 0 1 0
0 :0 0 0 0 0 0 0 0
------------------
4 :0 0 0 0 0 1 0 0
0 :0 0 0 0 0 0 0 0
------------------
8 :0 0 0 0 1 0 0 0
0 :0 0 0 0 0 0 0 0
------------------
16 :0 0 0 1 0 0 0 0
0 :0 0 0 0 0 0 0 0
------------------
32 :0 0 1 0 0 0 0 0
0 :0 0 0 0 0 0 0 0
------------------
64 :0 1 0 0 0 0 0 0
0 :0 0 0 0 0 0 0 0
------------------
128 :1 0 0 0 0 0 0 0
0 :0 0 0 0 0 0 0 0
Numero 0 : 0 0 0 0 0 0 0 0
Numero 1 : 0 0 0 0 0 0 0 1
Numero 2 : 0 0 0 0 0 0 1 0
Numero 3 : 0 0 0 0 0 0 1 1
Numero 4 : 0 0 0 0 0 1 0 0
Numero 5 : 0 0 0 0 0 1 0 1
Numero 6 : 0 0 0 0 0 1 1 0
Numero 7 : 0 0 0 0 0 1 1 1
Numero 8 : 0 0 0 0 1 0 0 0
Numero 9 : 0 0 0 0 1 0 0 1
Numero 10 : 0 0 0 0 1 0 1 0
Numero 11 : 0 0 0 0 1 0 1 1
Numero 12 : 0 0 0 0 1 1 0 0
Numero 13 : 0 0 0 0 1 1 0 1
Numero 14 : 0 0 0 0 1 1 1 0
Numero 15 : 0 0 0 0 1 1 1 1
Numero 16 : 0 0 0 1 0 0 0 0
Numero 17 : 0 0 0 1 0 0 0 1
Numero 18 : 0 0 0 1 0 0 1 0
Numero 19 : 0 0 0 1 0 0 1 1
Numero 20 : 0 0 0 1 0 1 0 0
Numero 21 : 0 0 0 1 0 1 0 1
Numero 22 : 0 0 0 1 0 1 1 0
Numero 23 : 0 0 0 1 0 1 1 1
Numero 24 : 0 0 0 1 1 0 0 0
Numero 25 : 0 0 0 1 1 0 0 1
Numero 26 : 0 0 0 1 1 0 1 0
Numero 27 : 0 0 0 1 1 0 1 1
Numero 28 : 0 0 0 1 1 1 0 0
Numero 29 : 0 0 0 1 1 1 0 1
Numero 30 : 0 0 0 1 1 1 1 0
Numero 31 : 0 0 0 1 1 1 1 1
Numero 32 : 0 0 1 0 0 0 0 0
Numero 33 : 0 0 1 0 0 0 0 1
Numero 34 : 0 0 1 0 0 0 1 0
Numero 35 : 0 0 1 0 0 0 1 1
Numero 36 : 0 0 1 0 0 1 0 0
Numero 37 : 0 0 1 0 0 1 0 1
Numero 38 : 0 0 1 0 0 1 1 0
Numero 39 : 0 0 1 0 0 1 1 1
Numero 40 : 0 0 1 0 1 0 0 0
Numero 41 : 0 0 1 0 1 0 0 1
Numero 42 : 0 0 1 0 1 0 1 0
Numero 43 : 0 0 1 0 1 0 1 1
Numero 44 : 0 0 1 0 1 1 0 0
Numero 45 : 0 0 1 0 1 1 0 1
Numero 46 : 0 0 1 0 1 1 1 0
Numero 47 : 0 0 1 0 1 1 1 1
Numero 48 : 0 0 1 1 0 0 0 0
Numero 49 : 0 0 1 1 0 0 0 1
Numero 50 : 0 0 1 1 0 0 1 0
Numero 51 : 0 0 1 1 0 0 1 1
Numero 52 : 0 0 1 1 0 1 0 0
Numero 53 : 0 0 1 1 0 1 0 1
Numero 54 : 0 0 1 1 0 1 1 0
Numero 55 : 0 0 1 1 0 1 1 1
Numero 56 : 0 0 1 1 1 0 0 0
Numero 57 : 0 0 1 1 1 0 0 1
Numero 58 : 0 0 1 1 1 0 1 0
Numero 59 : 0 0 1 1 1 0 1 1
Numero 60 : 0 0 1 1 1 1 0 0
Numero 61 : 0 0 1 1 1 1 0 1
Numero 62 : 0 0 1 1 1 1 1 0
Numero 63 : 0 0 1 1 1 1 1 1
Numero 64 : 0 1 0 0 0 0 0 0
Numero 65 : 0 1 0 0 0 0 0 1
Numero 66 : 0 1 0 0 0 0 1 0
Numero 67 : 0 1 0 0 0 0 1 1
Numero 68 : 0 1 0 0 0 1 0 0
Numero 69 : 0 1 0 0 0 1 0 1
Numero 70 : 0 1 0 0 0 1 1 0
Numero 71 : 0 1 0 0 0 1 1 1
Numero 72 : 0 1 0 0 1 0 0 0
Numero 73 : 0 1 0 0 1 0 0 1
Numero 74 : 0 1 0 0 1 0 1 0
Numero 75 : 0 1 0 0 1 0 1 1
Numero 76 : 0 1 0 0 1 1 0 0
Numero 77 : 0 1 0 0 1 1 0 1
Numero 78 : 0 1 0 0 1 1 1 0
Numero 79 : 0 1 0 0 1 1 1 1
Numero 80 : 0 1 0 1 0 0 0 0
Numero 81 : 0 1 0 1 0 0 0 1
Numero 82 : 0 1 0 1 0 0 1 0
Numero 83 : 0 1 0 1 0 0 1 1
Numero 84 : 0 1 0 1 0 1 0 0
Numero 85 : 0 1 0 1 0 1 0 1
Numero 86 : 0 1 0 1 0 1 1 0
Numero 87 : 0 1 0 1 0 1 1 1
Numero 88 : 0 1 0 1 1 0 0 0
Numero 89 : 0 1 0 1 1 0 0 1
Numero 90 : 0 1 0 1 1 0 1 0
Numero 91 : 0 1 0 1 1 0 1 1
Numero 92 : 0 1 0 1 1 1 0 0
Numero 93 : 0 1 0 1 1 1 0 1
Numero 94 : 0 1 0 1 1 1 1 0
Numero 95 : 0 1 0 1 1 1 1 1
Numero 96 : 0 1 1 0 0 0 0 0
Numero 97 : 0 1 1 0 0 0 0 1
Numero 98 : 0 1 1 0 0 0 1 0
Numero 99 : 0 1 1 0 0 0 1 1
Numero 100 : 0 1 1 0 0 1 0 0
Numero 101 : 0 1 1 0 0 1 0 1
Numero 102 : 0 1 1 0 0 1 1 0
Numero 103 : 0 1 1 0 0 1 1 1
Numero 104 : 0 1 1 0 1 0 0 0
Numero 105 : 0 1 1 0 1 0 0 1
Numero 106 : 0 1 1 0 1 0 1 0
Numero 107 : 0 1 1 0 1 0 1 1
Numero 108 : 0 1 1 0 1 1 0 0
Numero 109 : 0 1 1 0 1 1 0 1
Numero 110 : 0 1 1 0 1 1 1 0
Numero 111 : 0 1 1 0 1 1 1 1
Numero 112 : 0 1 1 1 0 0 0 0
Numero 113 : 0 1 1 1 0 0 0 1
Numero 114 : 0 1 1 1 0 0 1 0
Numero 115 : 0 1 1 1 0 0 1 1
Numero 116 : 0 1 1 1 0 1 0 0
Numero 117 : 0 1 1 1 0 1 0 1
Numero 118 : 0 1 1 1 0 1 1 0
Numero 119 : 0 1 1 1 0 1 1 1
Numero 120 : 0 1 1 1 1 0 0 0
Numero 121 : 0 1 1 1 1 0 0 1
Numero 122 : 0 1 1 1 1 0 1 0
Numero 123 : 0 1 1 1 1 0 1 1
Numero 124 : 0 1 1 1 1 1 0 0
Numero 125 : 0 1 1 1 1 1 0 1
Numero 126 : 0 1 1 1 1 1 1 0
Numero 127 : 0 1 1 1 1 1 1 1
Numero 128 : 1 0 0 0 0 0 0 0
Numero 129 : 1 0 0 0 0 0 0 1
Numero 130 : 1 0 0 0 0 0 1 0
Numero 131 : 1 0 0 0 0 0 1 1
Numero 132 : 1 0 0 0 0 1 0 0
Numero 133 : 1 0 0 0 0 1 0 1
Numero 134 : 1 0 0 0 0 1 1 0
Numero 135 : 1 0 0 0 0 1 1 1
Numero 136 : 1 0 0 0 1 0 0 0
Numero 137 : 1 0 0 0 1 0 0 1
Numero 138 : 1 0 0 0 1 0 1 0
Numero 139 : 1 0 0 0 1 0 1 1
Numero 140 : 1 0 0 0 1 1 0 0
Numero 141 : 1 0 0 0 1 1 0 1
Numero 142 : 1 0 0 0 1 1 1 0
Numero 143 : 1 0 0 0 1 1 1 1
Numero 144 : 1 0 0 1 0 0 0 0
Numero 145 : 1 0 0 1 0 0 0 1
Numero 146 : 1 0 0 1 0 0 1 0
Numero 147 : 1 0 0 1 0 0 1 1
Numero 148 : 1 0 0 1 0 1 0 0
Numero 149 : 1 0 0 1 0 1 0 1
Numero 150 : 1 0 0 1 0 1 1 0
Numero 151 : 1 0 0 1 0 1 1 1
Numero 152 : 1 0 0 1 1 0 0 0
Numero 153 : 1 0 0 1 1 0 0 1
Numero 154 : 1 0 0 1 1 0 1 0
Numero 155 : 1 0 0 1 1 0 1 1
Numero 156 : 1 0 0 1 1 1 0 0
Numero 157 : 1 0 0 1 1 1 0 1
Numero 158 : 1 0 0 1 1 1 1 0
Numero 159 : 1 0 0 1 1 1 1 1
Numero 160 : 1 0 1 0 0 0 0 0
Numero 161 : 1 0 1 0 0 0 0 1
Numero 162 : 1 0 1 0 0 0 1 0
Numero 163 : 1 0 1 0 0 0 1 1
Numero 164 : 1 0 1 0 0 1 0 0
Numero 165 : 1 0 1 0 0 1 0 1
Numero 166 : 1 0 1 0 0 1 1 0
Numero 167 : 1 0 1 0 0 1 1 1
Numero 168 : 1 0 1 0 1 0 0 0
Numero 169 : 1 0 1 0 1 0 0 1
Numero 170 : 1 0 1 0 1 0 1 0
Numero 171 : 1 0 1 0 1 0 1 1
Numero 172 : 1 0 1 0 1 1 0 0
Numero 173 : 1 0 1 0 1 1 0 1
Numero 174 : 1 0 1 0 1 1 1 0
Numero 175 : 1 0 1 0 1 1 1 1
Numero 176 : 1 0 1 1 0 0 0 0
Numero 177 : 1 0 1 1 0 0 0 1
Numero 178 : 1 0 1 1 0 0 1 0
Numero 179 : 1 0 1 1 0 0 1 1
Numero 180 : 1 0 1 1 0 1 0 0
Numero 181 : 1 0 1 1 0 1 0 1
Numero 182 : 1 0 1 1 0 1 1 0
Numero 183 : 1 0 1 1 0 1 1 1
Numero 184 : 1 0 1 1 1 0 0 0
Numero 185 : 1 0 1 1 1 0 0 1
Numero 186 : 1 0 1 1 1 0 1 0
Numero 187 : 1 0 1 1 1 0 1 1
Numero 188 : 1 0 1 1 1 1 0 0
Numero 189 : 1 0 1 1 1 1 0 1
Numero 190 : 1 0 1 1 1 1 1 0
Numero 191 : 1 0 1 1 1 1 1 1
Numero 192 : 1 1 0 0 0 0 0 0
Numero 193 : 1 1 0 0 0 0 0 1
Numero 194 : 1 1 0 0 0 0 1 0
Numero 195 : 1 1 0 0 0 0 1 1
Numero 196 : 1 1 0 0 0 1 0 0
Numero 197 : 1 1 0 0 0 1 0 1
Numero 198 : 1 1 0 0 0 1 1 0
Numero 199 : 1 1 0 0 0 1 1 1
Numero 200 : 1 1 0 0 1 0 0 0
Numero 201 : 1 1 0 0 1 0 0 1
Numero 202 : 1 1 0 0 1 0 1 0
Numero 203 : 1 1 0 0 1 0 1 1
Numero 204 : 1 1 0 0 1 1 0 0
Numero 205 : 1 1 0 0 1 1 0 1
Numero 206 : 1 1 0 0 1 1 1 0
Numero 207 : 1 1 0 0 1 1 1 1
Numero 208 : 1 1 0 1 0 0 0 0
Numero 209 : 1 1 0 1 0 0 0 1
Numero 210 : 1 1 0 1 0 0 1 0
Numero 211 : 1 1 0 1 0 0 1 1
Numero 212 : 1 1 0 1 0 1 0 0
Numero 213 : 1 1 0 1 0 1 0 1
Numero 214 : 1 1 0 1 0 1 1 0
Numero 215 : 1 1 0 1 0 1 1 1
Numero 216 : 1 1 0 1 1 0 0 0
Numero 217 : 1 1 0 1 1 0 0 1
Numero 218 : 1 1 0 1 1 0 1 0
Numero 219 : 1 1 0 1 1 0 1 1
Numero 220 : 1 1 0 1 1 1 0 0
Numero 221 : 1 1 0 1 1 1 0 1
Numero 222 : 1 1 0 1 1 1 1 0
Numero 223 : 1 1 0 1 1 1 1 1
Numero 224 : 1 1 1 0 0 0 0 0
Numero 225 : 1 1 1 0 0 0 0 1
Numero 226 : 1 1 1 0 0 0 1 0
Numero 227 : 1 1 1 0 0 0 1 1
Numero 228 : 1 1 1 0 0 1 0 0
Numero 229 : 1 1 1 0 0 1 0 1
Numero 230 : 1 1 1 0 0 1 1 0
Numero 231 : 1 1 1 0 0 1 1 1
Numero 232 : 1 1 1 0 1 0 0 0
Numero 233 : 1 1 1 0 1 0 0 1
Numero 234 : 1 1 1 0 1 0 1 0
Numero 235 : 1 1 1 0 1 0 1 1
Numero 236 : 1 1 1 0 1 1 0 0
Numero 237 : 1 1 1 0 1 1 0 1
Numero 238 : 1 1 1 0 1 1 1 0
Numero 239 : 1 1 1 0 1 1 1 1
Numero 240 : 1 1 1 1 0 0 0 0
Numero 241 : 1 1 1 1 0 0 0 1
Numero 242 : 1 1 1 1 0 0 1 0
Numero 243 : 1 1 1 1 0 0 1 1
Numero 244 : 1 1 1 1 0 1 0 0
Numero 245 : 1 1 1 1 0 1 0 1
Numero 246 : 1 1 1 1 0 1 1 0
Numero 247 : 1 1 1 1 0 1 1 1
Numero 248 : 1 1 1 1 1 0 0 0
Numero 249 : 1 1 1 1 1 0 0 1
Numero 250 : 1 1 1 1 1 0 1 0
Numero 251 : 1 1 1 1 1 0 1 1
Numero 252 : 1 1 1 1 1 1 0 0
Numero 253 : 1 1 1 1 1 1 0 1
Numero 254 : 1 1 1 1 1 1 1 0
Numero 255 : 1 1 1 1 1 1 1 1*/
