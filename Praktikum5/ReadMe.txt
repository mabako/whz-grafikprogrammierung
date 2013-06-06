================================================================================
    MICROSOFT FOUNDATION CLASS-BIBLIOTHEK: 
    Prak3_A0-Projekt�bersicht
===============================================================================

Der Anwendungs-Assistent hat diese Prak3_A0-Anwendung f�r Sie 
erstellt. Diese Anwendung zeigt nicht nur die Grundlagen der Verwendung von 
Microsoft Foundation Classes, sondern dient auch als Ausgangspunkt f�r das 
Schreiben Ihrer Anwendung.

Diese Datei bietet eine �bersicht �ber den Inhalt der einzelnen Dateien, aus
denen Ihre Prak3_A0-Anwendung besteht.

Prak3_A0.vcproj
    Dies ist die Hauptprojektdatei f�r VC++-Projekte, die mithilfe eines 
    Anwendungs-Assistenten erstellt werden.
    Sie enth�lt Informationen zur Visual�C++-Version, mit der die Datei 
    generiert wurde, sowie Informationen zu Plattformen, Konfigurationen und 
    Projektfeatures, die mit dem Anwendungs-Assistenten ausgew�hlt wurden.

Prak3_A0.h
    Dies ist die Hauptheaderdatei f�r die Anwendung. Sie enth�lt weitere
    projektspezifische Header (einschlie�lich "Resource.h") und deklariert
    die CPrak3_A0App-Anwendungsklasse.

Prak3_A0.cpp
    Dies ist die Quelldatei der Hauptanwendung, die die CPrak3_A0App-
    Anwendungsklasse enth�lt.

Prak3_A0.rc
    Dies ist eine Auflistung aller vom Programm verwendeten 
    Microsoft Windows-Ressourcen. Sie enth�lt die Symbole, Bitmaps und Cursor, 
    die im Unterverzeichnis "RES" gespeichert werden. Diese Datei kann direkt 
    in Microsoft Visual C++ bearbeitet werden. Ihre Projektressourcen befinden 
    sich in 1031.

res\Prak3_A0.ico
    Dies ist eine Symboldatei, die als Symbol der Anwendung verwendet wird. 
    Dieses Symbol ist in der Hauptressourcendatei "Prak3_A0.rc" 
    enthalten.

res\Prak3_A0.rc2
    Diese Datei enth�lt Ressourcen, die nicht von Microsoft Visual C++ 
    bearbeitet werden. Sie sollten alle Ressourcen, die nicht mit dem
    Ressourcen-Editor bearbeitet werden k�nnen, in dieser Datei platzieren.


/////////////////////////////////////////////////////////////////////////////

Der Anwendungs-Assistent erstellt eine Dialogfeldklasse:

Prak3_A0Dlg.h, Prak3_A0Dlg.cpp � das Dialogfeld
    Diese Dateien enthalten Ihre CPrak3_A0Dlg-Klasse. Diese Klasse 
    bestimmt das Verhalten des Hauptdialogfelds Ihrer Anwendung. Die Vorlage 
    des Dialogfelds befindet sich in der Datei "Prak3_A0.rc", die 
    in Microsoft Visual C++ bearbeitet werden kann.


/////////////////////////////////////////////////////////////////////////////

Weitere Funktionen:

ActiveX-Steuerelemente
    Die Anwendung unterst�tzt die Verwendung von ActiveX-Steuerelementen.

Druck- und Seitenansichtunterst�tzung
    Der Anwendungs-Assistent hat Code generiert, um die Befehle f�r Drucken, 
    Druckeinrichtung und Seitenansicht zu verarbeiten, indem Memberfunktionen 
    in der CView-Klasse aus der MFC-Bibliothek aufgerufen werden.

/////////////////////////////////////////////////////////////////////////////

Andere Standarddateien:

StdAfx.h, StdAfx.cpp
    Mit diesen Dateien werden eine vorkompilierte Headerdatei (PCH)
    mit dem Namen "Prak3_A0.pch" und eine 
    vorkompilierte Typendatei mit dem Namen "StdAfx.obj" erstellt.

Resource.h
    Dies ist die Standardheaderdatei, die neue Ressourcen-IDs definiert.
    Die Datei wird mit Microsoft�Visual�C++ gelesen und aktualisiert.

Prak3_A0.manifest
	Anwendungsmanifestdateien werden in Windows�XP zur Beschreibung einer
	Anwendungsabh�ngigkeit von verschiedenen Versionen paralleler 
        Assemblys verwendet. 
	Das Ladeprogramm verwendet diese Informationen, um die entsprechende 
	Assembly aus dem Assemblycache oder privat aus der Anwendung zu laden.
	Das Anwendungsmanifest kann zur Verteilung als externe Manifestdatei 
        enthalten sein, die im gleichen Ordner installiert ist wie die 
        ausf�hrbare Datei der Anwendung, oder sie kann in Form einer Ressource 
        in der ausf�hrbaren Datei enthalten sein.
/////////////////////////////////////////////////////////////////////////////

Weitere Hinweise:

Der Anwendungs-Assistent verwendet "TODO:", um auf Teile des Quellcodes
hinzuweisen, die Sie erg�nzen oder anpassen sollten.

Wenn Ihre Anwendung MFC in einer gemeinsam genutzten DLL verwendet, 
m�ssen Sie die MFC-DLLs verteilen. Wenn die Anwendung eine andere Sprache 
als die des Gebietsschemas des Betriebssystems verwendet, m�ssen Sie au�erdem 
die entsprechenden lokalisierten Ressourcen in "MFC90XXX.DLL" verteilen.
Weitere Informationen zu diesen beiden Themen finden Sie im Abschnitt 
zum Verteilen von Visual C++-Anwendungen in der Dokumentation zu MSDN.

/////////////////////////////////////////////////////////////////////////////
