using System;
using System.IO;

public class Dirs {
  public static void listing(string startdir){
    foreach (string dir
              in Directory.GetDirectories(startdir)){
      Console.WriteLine(dir);
      listing(dir);
    }
  }

  public static void Main(){
    listing(".");
  }
}

  
