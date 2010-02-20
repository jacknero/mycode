using System.Xml;
using System.IO;
using System.Text;

namespace ConsoleApplication1
{
  class Program
  {
    static void Main(string[] args)
    {
      StringBuilder output = new StringBuilder();

      string xmlString =
        @"<bookstore>
        <book genre='autobiography' publicationdate='1981-03-22' ISBN='1-861003-11-0'>
        <title>The Autobiography of Benjamin Franklin</title>
        <author>
        <first-name>Benjamin</first-name>
        <last-name>Franklin</last-name>
        </author>
        <price>8.99</price>
        </book>
        </bookstore>";

      // Create an XmlReader
      using (XmlReader reader = XmlReader.Create(new StringReader(xmlString)))
      {
        reader.ReadToFollowing("book");
        reader.MoveToFirstAttribute();
        string genre = reader.Value;
        output.AppendLine("The genre value: " + genre);

        reader.ReadToFollowing("title");
        output.AppendLine("Content of the title element: " + reader.ReadElementContentAsString());
      }

      System.Console.WriteLine(output.ToString());
    }
  }
}
