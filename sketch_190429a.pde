// M.Wolak        //
// ENME351        //
// S19 Mitchel    //
// Final Project  //
// Lab 9          //

//  The following code was based on peices from Lab 6 github code and inspired by Matt Ambrogi //

import processing.serial.*;                            // add serial library
//import processing.video.*;                             // video option
Serial myPort;                                         // declare myPort
PImage img, img2;                                      // declare img variables
// myMovie;                                               // video opt

void setup(){
  size(512,512);                                       // window size
  printArray(Serial.list());                           // list all available serial ports
  myPort = new Serial(this, Serial.list()[0], 9600);   // define input port
  myPort.clear();                                      // clear the port of any initial junk
  background(125);                                     // background gray
  
  img = loadImage("Curb.gif");                        // image load
  img2= loadImage("Sein.gif");                       // image2 load
  //myMovie = new Movie(this, "curb.mp4");                // video option
  //myMovie.play();
  
}

void draw(){
  if (myPort.available () > 0) {                       // make sure port is open
  String inString = myPort.readStringUntil('\n');      // read input string
  if (inString != null) {                              // ignore null strings
  inString = trim(inString);                           // trim off any whitespace
  
  String Curb = ("Curb Your Enthusiasm");              // read "Curb..." as Curb
  String Sein = ("Seinfeld");
  
  println(inString);                                   // print to processing monitor
  
  if (inString.equals(Curb) == true){                  // if string is read, display image
    image(img,50,50);                                  // image
    fill(225);                                         // white rectangle
    rect(50, 332, 500, 92);
    textSize(48);                                      // text with color and size
    fill(225,225,0);
    text("CURB IT JERRY!", 102, 402);
    textSize(48);
    fill(0);
    text("CURB IT JERRY!", 100, 400);
    //img.resize(1000,748);
    }
  if (inString.equals(Sein) == true){                  // if Sein string is read, display image
    image(img2,50,50);
    //img2.resize(1000,748);
  }
  }
}

}
