using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.IO;
using System.Xml;

namespace ConsoleApplication1
{
  class Program
  {
    static void Main(string[] args)
    {
      System.Console.WriteLine("Hello, World!");
      WebRequest req = WebRequest.Create("http://www.yahoo.co.jp/");
      WebResponse rsp = req.GetResponse();
      Stream stm = rsp.GetResponseStream();
      if (stm != null)
      {
        StreamReader reader = new StreamReader(stm, System.Text.Encoding.GetEncoding("utf-8"));
        //System.Console.WriteLine(reader.ReadToEnd());
        using (XmlReader xmlReader = XmlReader.Create(reader))
        stm.Close();
      }
      rsp.Close();
      System.Threading.Thread.Sleep(1000);
    }
  }
}

