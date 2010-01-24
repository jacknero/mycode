using System;
using System.Net;
using System.Text.RegularExpressions;

class RegexReplace{
  static void Main(){
    WebClient wc = new WebClient();
    string html = wc.DownloadString("http://www.atmarkit.co.jp/");

    Regex re1 = new Regex("<(no)?script.*?script>",
        RegexOptions.IgnoreCase | RegexOptions.Singleline);

    Regex re2 = new Regex("<.*?>", RegexOptions.Singleline);

    html = re1.Replace(html, "");
    html = re2.Replace(html, "");

    Console.WriteLine(html);
  }
}
