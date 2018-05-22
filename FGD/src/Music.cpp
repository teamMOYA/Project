#include "Music.h"
#include <allegro.h>

Music::Music(){

    this->init();

}

/**
Funcion que carga todos los ficheros de audio
*/
void Music::init(){
    set_volume(230, 90);

  this->map1 =  load_sample("src\\Resources\\Music\\wah_fuzz.wav");


}

void Music::soundMap1()
{
    play_sample( this->map1, 100, 128, 900, 1);
}

void Music::stopSoundBackground(){
     stop_sample( this->map1 );
}


/*void sonido_pasos(){
     play_sample ( spasos, 100,128, 3300, 0 );
}

void sonido_abrirpuerta(){
     play_sample ( spuerta1, 100,128, 1300, 0 );
}

void sonido_ambiente(){
     play_sample ( sbosque, 80,128, 900, 1 );
}

void para_sonido_ambiente(){
     stop_sample( sbosque );
}*/