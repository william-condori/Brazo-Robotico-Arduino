#include <Servo.h>

char dato;
Servo hombro, codo, muneca, pinzas, base;
int phombro, pcodo, pmuneca, ppinzas, pbase, contador=0;

void setup()
{
  hombro.attach(13);
  codo.attach(12);
  muneca.attach(11);
  pinzas.attach(10);
  base.attach(9);
  Serial.begin(9600);
}

void loop()
{
  if(contador==0)
  {
    // Leer posicion inicial
    phombro=hombro.read();
    pcodo=codo.read();
    pmuneca=muneca.read();
    ppinzas=pinzas.read();
    pbase=base.read();
    
    //Escribir posicion inicial
    hombro.write(phombro);
    codo.write(pcodo);
    muneca.write(pmuneca);
    pinzas.write(ppinzas);
    base.write(pbase);
    contador++;
  }
  dato='x';
  dato=Serial.read();
  switch(dato)
  {
    case 'A': //HOMBRO DERECHA
    {
       while(Serial.read()!='x')
       {
          if(phombro>=175)
              phombro=175;
          if(phombro<=180 && phombro>=0)
          {
            
            phombro++;
            hombro.write(phombro);
            delay(15);
          }
       }
      break;  
    }
    
    case 'a': //HOMBRO IZQUIERDA
    {
       while(Serial.read()!='x')
       {
         if(phombro<=5)
              phombro=5; 
         if(phombro<=180 && phombro>=0)
          {
            phombro--;
            hombro.write(phombro);
            delay(15);
          }
      }
      break;  
    }
    case 'C': //CODO ARRIBA
    {
         if(pcodo>=175)
              pcodo=175;
        while(Serial.read()!='x')
        {
          if(pcodo<=180 && pcodo>=0)
          {
            pcodo++;
            codo.write(pcodo);
            delay(15);
          }
        }
      break;   
    }
    case 'c': //CODO ABAJO
    {
       if(pcodo<=5)
              pcodo=5;
       while(Serial.read()!='x')
       {
          if(pcodo<=180 && pcodo>=0)
          {
            pcodo--;
            codo.write(pcodo);
            delay(15);
          }
       }
      break;   
    }
    case 'I': //MUÑECA ARRIBA
    {
      if(pmuneca>=170)
          pmuneca=170; 
      while(Serial.read()!='x')
       {
          if(pmuneca<=180 && pmuneca>=0)
          {
            pmuneca++;
            muneca.write(pmuneca);
            delay(15);
          }
       }
      break;      
    }
    case 'i': //MUÑECA ABAJO
    {
        if(pmuneca<=10)
              pmuneca=10;
       while(Serial.read()!='x')
       {
          if(pmuneca<=180 && pmuneca>=0)
          {
            pmuneca--;
            muneca.write(pmuneca);
            delay(15);
          }
       }
      break; 
    }
    case 'P': //PINZA ABRIR
    {
      if(ppinzas>=165)
          ppinzas=165; 
      while(Serial.read()!='x')
       {
           if(ppinzas<=180 && ppinzas>=0)
          {
            ppinzas++;
            pinzas.write(ppinzas);
            delay(15);
          }
       }
      break; 
    }
    case 'p': //PINZA CERRAR
    {
        if(ppinzas<=15)
              ppinzas=15;      
       while(Serial.read()!='x')
       {
          if(ppinzas<=180 && ppinzas>=0)
          {
            ppinzas--;
            pinzas.write(ppinzas);
            delay(15);
          }
       }
      break; 
    }
    case 'B': //BASE IZQUIERDA
    {  if(pbase>=175)
          pbase=175;
       while(Serial.read()!='x')
       {
           if(pbase<=180 && pbase>=0)
          {
            pbase++;
            base.write(pbase);
            delay(15);
          }
       }
      break; 
    }
    case 'b': //BASE DERECHA
    {
        if(pbase<=5)
              pbase=5; 
       while(Serial.read()!='x')
       {
          if(pbase<=180 && pbase>=0)
          {
            pbase--;
            base.write(pbase);
            delay(15);
          }
       }
      break; 
    }
  }
}
