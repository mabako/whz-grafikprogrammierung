#pragma once
//#include "datenbasis.h"  // Bei Projekten mit Datenbasis

// Beachte:
// Die Implementierungsdateien von CPunkt und CVektor 
// müssen ins Projekt eingebunden werden, da diese Klassen
// von der Klasse COpenGLMaus verwendet werden.

class CGrafik 
{
private:
	
public:
	// Daten
	GLuint m_imaxNr; // Größte Objektnummer
	CDatenBasis m_DatenBasis; // Datenbasis

	// Allgemeine Methoden	
	CGrafik(void);
	~CGrafik(void);
	void Init();
	void Draw();
	void drawObjects(GLenum);  // Zeichnet alle Displaylisten neu
	
	// Aufgabenspezifische Methoden

};
