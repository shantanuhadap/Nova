import processing.serial.*;

Serial myPort;

int default1 = 90;
int default2 = 110;
int default3 = 90;
int default4 = 90;

void setup(){
  size(360, 360);
  myPort = new Serial(this, "COM4", 9600);
  myPort.bufferUntil('\n');
}

void draw(){

  background(0,0,0);
  
  if(mousePressed && (mouseButton == LEFT)) {   

    default1 = mouseX/2;
    default2 = mouseY/2;
    myPort.write(mouseX/2);
    myPort.write(mouseY/2);
    myPort.write(default3);
    myPort.write(default4);
    
  }
  
  if(mousePressed && (mouseButton == RIGHT)){
    
    default3 = mouseX/2;
    default4 = mouseY/2;
    myPort.write(default1);
    myPort.write(default2); 
    myPort.write(default3);
    myPort.write(default4);
  }
 
  if(keyPressed && (key == 'a')){
    
    myPort.write(default1);
    myPort.write(default2);
    myPort.write(default3);
    myPort.write(default4);
  }
 

  if(keyPressed && (key == 'd')){
    
    myPort.write(default1);
    myPort.write(default2);
    myPort.write(default3);
    myPort.write(default4);
  }
  
}

void keyPressed(){

 switch(key){
   case 'a':
   default1 = default1 + 2;
   break;
   case 'd':
   default1 = default1 - 2;
   break;
  }
  
}
