#pragma once

#ifdef _DEBUG
#pragma comment(lib, "../../gks/GServer100D.lib")
#else
#pragma comment(lib, "../../gks/GServer100.lib")
#endif

// CServer-Befehlsziel

#define GKS_SUBWINDOW 0
// Integer
typedef long int Gint;
// Float
typedef float Gfloat;
// Bereichdefinition
struct Glimit {
		Gfloat x_min;
		Gfloat x_max;
		Gfloat y_min;
		Gfloat y_max;
		};
// 2d - Punkt
struct Gpoint {
		Gfloat x, y;
		};
// Punktliste
struct Gpoint_list {
		Gint num_points;
		Gpoint *points;
		};
// Vektor
struct Gvec {
		Gfloat delta_x;
		Gfloat delta_y;
		};
// Füllart
typedef enum 
{		
		GSTYLE_HOLLOW,
		GSTYLE_SOLID,
		GSTYLE_PAT,
		GSTYLE_HATCH
} Gfill_int_style;
// Farbe
struct Grgb	{
		Gfloat red;		// red intensity
		Gfloat green;	// green intensity
		Gfloat blue;	// blue intensity
		};
// Farbe
union Gcolr_rep {
		Grgb rgb;
		};

// 2x3 Matrix
typedef Gfloat Gtran_matrix[2][3];

// Koordinaten
typedef enum
{
	GCOORD_WC, /* world coordinates */
	GCOORD_NDC /* normalized device coordinates */
} Gcoord;

// Text Schreibrichtung
typedef enum
{
	GPATH_RIGHT,
	GPATH_LEFT,
	GPATH_UP,
	GPATH_DOWN
} Gtext_path;

// horizontale Textausrichtung
typedef enum
{
	GHOR_NORM,
	GHOR_LEFT,
	GHOR_CTR,
	GHOR_RIGHT
} Ghor_text_align;

// vertikale Textausrichtung
typedef enum
{
	GVERT_NORM,
	GVERT_TOP,
	GVERT_CAP,
	GVERT_HALF,
	GVERT_BASE,
	GVERT_BOTTOM
} Gvert_text_align;

// Text Ausrichtung
typedef struct 
{
	Ghor_text_align  hor;	// horizontale komponente
	Gvert_text_align vert;	// vertikale komponente
}Gtext_align;

/* Gint_size - integer size */
 typedef struct
 {
   Gint size_x;
   Gint size_y;
 } Gint_size;

/* Gpat_rep - pattern representation*/
 typedef struct
 {
   Gint_size dims;
   Gint *colr_array;
 } Gpat_rep;

 /* Gfloat_size - float size */
 typedef struct
 {
   Gfloat size_x;
   Gfloat size_y;
 } Gfloat_size;

 // Segmentattribute
 // Datentypen
 // Identifizierbarkeit
 typedef enum
 {
	 GSEG_UNDET, GSEG_DET
 } Gdet;
 // Hervorheben
 typedef enum
 {
	 GSEG_NORM, GSEG_HIGHL
 } Ghighl;
 // Sichtbarkeit
 typedef enum
 {
	 GSEG_INVIS, GSEG_VIS
 } Gvis;
 // Struktur
 typedef struct
 {
	 Gtran_matrix	tran_matrix;
	 Gvis			vis;
	 Ghighl			highl;
	 Gfloat			pri;
	 Gdet			det;
 } Gseg_attrs;
	
// Inquiry type
typedef enum
{
	GINQ_SET, GINQ_REALIZED
} Ginq_type;
 
 
 // Farbmodell
#define MAX_INTENSITY 255

// Linienarten
#define GLINE_SOLID			1
#define GLINE_DASH			2
#define GLINE_DOT			3
#define GLINE_DASH_DOT		4
#define GLINE_DASH_DOT_DOT	5

// marker types */

#define GMARKER_DOT          (1) /* Dotted marker type               */
#define GMARKER_PLUS         (2) /* Plus (+) marker type             */
#define GMARKER_ASTERISK     (3) /* Asterisk (*) marker type         */
#define GMARKER_CIRCLE       (4) /* Circle (o) marker type           */
#define GMARKER_CROSS        (5) /* Cross (x) marker type            */


// hatch styles 

#define GHATCH_HOR			(1) //  horizontal hatch lines
#define GHATCH_VERT			(2) //  vertical hatch lines
#define GHATCH_DIAG_45		(3) //  diagonal hatch lines 45 degree
#define GHATCH_DIAG_135		(4) //  diagonal hatch lines 135 degree
#define GHATCH_HOR_VERT		(5) //  horizontal and vertical hatch lines
#define GHATCH_DIAG_45_135	(6) //  diagonal hatch lines 45 and 135 degree

class AFX_EXT_CLASS CServer : public CObject
{
public:
	CServer();
	virtual ~CServer();

// Attribute
private:
	// Der eigentliche Server
	CFrameWnd* m_ServerWnd;
	// Zeiger auf Protokolldatei
	FILE* m_FlogFile;
// Operationen
public:
	// Starten des Servers
	int gopen_gks(char*);
	// Beenden des Servers
	int gclose_gks();
	
	//Workstation anlegen
	int gopen_ws(Gint ws_id, const void* channel, Gint ws_type);			
	//WS-Window setzen
	int gx_set_win(Gint ws_id,Gfloat x_min,Gfloat x_max,Gfloat y_min,Gfloat y_max);
	//WS-Viewport setzen
	int gx_set_vp(Gint ws_id,Gfloat x_min,Gfloat x_max,Gfloat y_min,Gfloat y_max);
	//Workstation schliessen
	int gclose_ws(Gint ws_id);			
	//Workstation aktivieren
	int gactivate_ws(Gint ws_id);			
	//Workstation deaktivieren
	int gdeactivate_ws(Gint ws_id);				
	//Workstation löschen
	int gx_clear_ws(Gint ws_id);	

	//Segment erstellen
	int gcreate_seg(Gint seg_id);			
	//Segment schliessen
	int gclose_seg();
	//Segment löschen
	int gdel_seg(Gint seg_id);			
	//Segment einer WS zuordnen
	int gassoc_seg_ws(Gint ws_id,Gint seg_id);
	// Segment-Trafo setzen
	int gset_seg_tran(Gint segID, Gtran_matrix NewMatrix);
	// Segment-Priorität setzen
	int gset_seg_pri(Gint segID, Gfloat seg_pri);
	// Segment-Sichtbarkeit setzen
	int gset_vis(Gint segID, Gvis vis);

	//Polylinie zeichnen
	int gpolyline(const Gpoint_list* plst );
	//Linientyp
	int gset_linetype(Gint type);				
	//Linienbreite
	int gset_linewidth(Gfloat width);			
	//Farbindex
	int gset_line_colr_ind(Gint ind);

	//Polymarker zeichnen
	int gpolymarker(const Gpoint_list* plst);
	// Markertyp setzen
	int gset_marker_type(Gint type);
	//Markenvergrößerungsfaktor
	int gset_marker_size(Gfloat size);			
	//Farbindex
	int gset_marker_colr_ind(Gint ind);

	//Fill-Area zeichnen
	int gfill_area(const Gpoint_list* plst);
	//Füllgebietsausfüllung
	int gset_fill_int_style(Gfill_int_style style);	
	//Ausfüllindex (Muster)
	int gset_fill_style_ind(Gint ind);				
	//Farbindex
	int gset_fill_colr_ind(Gint ind);

	// Pattern Reference Punkt setzen
	int gset_pat_ref_point(const Gpoint *pat_ref_point);

	// Pattern Size setzen
	int gset_pat_size(const Gfloat_size *pat_size);

	//Kreis zeichnen
	int gx_circle(const Gpoint_list* plst);

	int gaccum_tran_matrix(Gtran_matrix Matrix1, const Gpoint* FixP, const Gvec* Trans,Gfloat Winkel,
		const Gvec* Scale,int SW,Gtran_matrix& Matrix2);

	int geval_tran_matrix(const Gpoint* FixP, const Gvec* Trans,Gfloat Winkel,
		const Gvec* Scale,int SW,Gtran_matrix& Matrix);

	// Inquire-Funktionen
	int ginq_colr_rep(
		Gint		ws_id,
		Gint		colr_ind,
		Ginq_type	type,
		Gint*		err_ind,
		Gcolr_rep*	colr_rep
		);

	int gx_get_tran_matrix(Gint segID, Gtran_matrix& Matrix);

	
	// Workstation-Tabellen setzen
	// Farb-Tabelle
	int gset_colr_rep(Gint ws_id, Gint colr_ind, Gcolr_rep* colr_rep);
	// Muster-Tabelle
	int gset_pat_rep(Gint ws_id, Gint pat_ind, Gpat_rep* pat_rep);

	// Text zeichnen
	int gtext(const Gpoint* p,const char* txt);
	// Farbindex
	int gset_text_colr_ind(Gint ind);
	// Zeichenhöhe
	int gset_char_ht(Gfloat height);
	// Zeichenbreite
	int gset_char_expan(Gfloat width);
	// Zeichenabstand
	int gset_char_space(Gfloat space);
	// Zeichenaufwärtsvektor
	int gset_char_up_vec(const Gvec* upvec);
	// Text Schreibrichtung
	int gset_text_path(Gtext_path path);
	// Text Ausrichtung 
	int gset_text_align(Gtext_align* align);

	int gx_MoveWindow(int x, int y, int cx, int cy);
};


