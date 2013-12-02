// Filnamn : .../Life/Celler.h

/* 
   En klass som simulerar 'Game of life'. 
   Man vill studera en modell av en cellpopulations 
   liv. Cellerna tänks ligga på en kvadratisk bricka 
   som är indelad i rutor, där varje ruta kan 
   innehålla en cell. Varje cell kan vara levande 
   eller död. Man börjar med givet initialtillstånd 
   av levande celler och studerar hur cellpopulationen 
   förändras i tiden. Dessa förändringar innebär 
   helt enkelt att celler dör eller föds beroende på 
   hur omgivningen till dessa ser ut. Ett steg framåt 
   i tiden ger en nu s k generation av celler på brickan.

   En bricka med celler som kommer att ändra
   antalet celler enligt vissa spelregler:
   * Om en levande cell har ingen eller enbart 
     en granne så dör den av isolering.
   * Om en levande cell har två eller tre grannar 
     så överlever den till nästa generation.
   * Om en levende cell har fyra eller fler grannar 
     så dör den p g a 'överbefolkning' och näringsbrist.
   * Om en död cell har exakt tre levande grannar 
     så föds en ny cell på samma plats. Man kan se det 
     som att den döda cellen blir levande i nästa generation.
*/

#ifndef __CELLS__
#define __CELLS__

const int MAX = 30;       // Brickans maxstorlek

class Cells {
 public:
  Cells();

  void initiate();
  void newGeneration();

 private:
  int plate[MAX][MAX];    // 'Bricka' med celler
  int size;               // Storlek på 'brickan'
  char form;              // Initialmönster

  // Privata metoder
  void readSize();
  void readForm();
  void zeroit(int arr[][MAX]);
  void initX();
  void initY();
  void initZ();
  void initS();
  int neighbours(int i, int j);
  void draw(int temp[][MAX]);
};
#endif


