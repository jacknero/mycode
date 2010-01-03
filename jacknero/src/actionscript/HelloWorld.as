package{
  import flash.display.*;
  import flash.text.*;
  import flash.events.Event;

  public class HelloWorld extends Sprite {
    private var _timer:BeatTimer;
    public function HelloWorld(){
      var textField:TextField=new TextField();
      textField.text="HelloWorld!";
      textField.x = 50;
      textField.y = 70;
      var sp3:Sprite = new Sprite();
      sp3.x = 160;
      sp3.y =  20;
      sp3.graphics.lineStyle(5,0x0000FF,1);
      sp3.graphics.beginFill(0xFFCC00);
      //sp3.graphics.drawRect(0,0,140,140);
      sp3.graphics.drawCircle(20, 20, 18);
      //sp3.addChild(textField);
      addChild(sp3);
      var sp2:Sprite = new Sprite();
      sp2.x = 110;
      sp2.y =  50;
      sp2.graphics.lineStyle(5,0x00FF00,1);
      sp2.graphics.moveTo(  0,-30);
      sp2.graphics.lineTo( 30, 10);
      sp2.graphics.lineTo(-30, 10);
      sp2.graphics.lineTo(  0,-30);
      addChild(sp2);
      _timer= new BeatTimer();
      _timer.start(120);



      addEventListener(Event.ENTER_FRAME,function(event:Event):void{
          _timer.update();
          if(_timer.phase <= 0.2){
            sp3.graphics.clear();
      sp3.graphics.lineStyle(5,0x0000FF,1);
      sp3.graphics.beginFill(0xFFCC00);
           sp3.graphics.drawCircle(20, 20, 30);
          }
          if(_timer.phase > 0.2){
            sp3.graphics.clear();
      sp3.graphics.lineStyle(5,0x0000FF,1);
      sp3.graphics.beginFill(0xFFCC00);
           sp3.graphics.drawCircle(20, 20, 18);
            sp3.scaleX = 1;
            sp3.scaleY = 1;
          }
          if(_timer.isOnBeat){
          }
          });

    }
  }
}

