import gab.opencv.*;
import java.awt.Rectangle;
import processing.serial.*;
import processing.video.*;

OpenCV opencv;
Serial CreoqodeNova_Port;
Rectangle[] faces;
Capture video;
int avgX;
int avgY;

void setup(){

  size(640 , 480);
  
  video = new Capture(this, 640 , 480);
  
  opencv = new OpenCV(this, 640 , 480);
  opencv.loadCascade(OpenCV.CASCADE_FRONTALFACE); 

  video.start();
 
  CreoqodeNova_Port = new Serial(this, "COM4", 9600);
  CreoqodeNova_Port.bufferUntil('\n');
 
  faces = opencv.detect();

}

void draw(){

  scale(1);
  opencv.loadImage(video);

  image(video, 0, 0 );

  noFill();
  stroke(0, 255, 0);
  strokeWeight(2);
  Rectangle[] faces = opencv.detect();
  println(faces.length);

  for (int i = 0; i < faces.length; i++) {
    
    println(faces[i].x + "," + faces[i].y + "," + faces[i].width + "," + faces[i].height);
    rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
           
    avgX = faces[i].x + faces[i].width/2;
    avgY = faces[i].y + faces[i].height/2;
 
    //fill(255);
    //strokeWeight(2.0);
    
    //stroke(0);
    //ellipse(avgX, avgY, 8, 8);
   
    //stroke(255, 0, 0);
    //point(avgX, avgY);

    avgX = ( avgX * 50 / 177 );
    avgY = ( avgY * 40 / 133 );
    
    CreoqodeNova_Port.write(avgX);
    CreoqodeNova_Port.write(avgY);

  }

}

void captureEvent(Capture c) {
  c.read();
}
