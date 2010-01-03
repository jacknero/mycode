package {
  import flash.display.*;
  import flash.text.*;
  import flash.events.*;
  [SWF(frameRate="24", backgroundColor="#000000")]  
    public class Cube extends Sprite {
      private var sp:Sprite;
      private var faceArray:Array;
      private const CUBE_SCALE:int = 100;        

      public function Cube() {                        
        init();                        
      }
      private function init():void {
        createCubeFace();

        addEventListener(Event.ENTER_FRAME, function(e:Event):void {
            sp.rotationY += 1;
            sp.rotationX += 1;
            });
      }
      private function createCubeFace():void {
        sp = new Sprite();
        addChild(sp);
        sp.x = 250;
        sp.y = 200;
        var s:Sprite;
        faceArray = new Array();
        function createFace(c:uint):Sprite {
          var s:Sprite = new Sprite();
          drawRect(s, c);
          sp.addChild(s);
          return s
        }

        s = createFace(0xff0000);
        s.z = CUBE_SCALE/2;
        var t:TextField = new TextField();
        s.addChild(t);
        t.text = "日本語Flash";
        t.autoSize = TextFieldAutoSize.LEFT;
        t.setTextFormat(new TextFormat("test2", 15, 0xeeeeee));
        t.x = -50
          t.y = -20

          s = createFace(0x0000ff);
        s.rotationY = 90;
        s.x = -CUBE_SCALE/2;

        s = createFace(0x00ff00);
        s.rotationY = 90;
        s.x = CUBE_SCALE/2;

        s = createFace(0xffff00);
        s.rotationX = 90;
        s.y = -CUBE_SCALE/2;
        s = createFace(0x00ffff);
        s.rotationX = 90;
        s.y = CUBE_SCALE/2;
        s = createFace(0xaaaaaa);
        s.z = -CUBE_SCALE/2;
        t = new TextField();
        s.addChild(t);
        t.text = "ActionScript";
        t.autoSize = TextFieldAutoSize.LEFT;
        t.setTextFormat(new TextFormat("Test", 15, 0xeeeeee));
        t.x = -50
          t.y = -20

      }
      private function drawRect(s:Sprite, c:uint):void {
        var g:Graphics = s.graphics;
        g.lineStyle(2, 0xffffff);
        g.beginFill(c, 0); 
                   g.drawRect(-CUBE_SCALE/2, -CUBE_SCALE/2, CUBE_SCALE, CUBE_SCALE);
        g.endFill();

      }

    }

}
