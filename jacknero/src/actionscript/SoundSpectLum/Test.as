package {
  import flash.display.Sprite;
  import flash.display.Graphics;
  import flash.events.Event;
  import flash.media.Sound;
  import flash.media.SoundChannel;
  import flash.media.SoundMixer;
  import flash.net.URLRequest;
  import flash.utils.ByteArray;

  public class Sound2Visual extends Sprite {

    const PLOT_HEIGHT:int=100;
    const CHANNEL_LENGTH:int=200;

    var snd:Sound;
    var req:URLRequest;
    var channel:SoundChannel;
    var bytes:ByteArray;
    var g:Graphics;

    var _mc:MVI_0419_0000;
    var _mc1:MVI_0419_0000;
    var _mc2:MVI_0419_0000;
    var _mc3:MVI_0419_0000;
    var _mc4:MVI_0419_0000;
    var _mc5:MVI_0419_0000;
    var _mc6:MVI_0419_0000;
    var _mc7:MVI_0419_0000;
    var _mc8:MVI_0419_0000;

    var _maxFrame:Number=2700;
    var _flame0:Number=80;
    var _flame1:Number=70;
    var _flame2:Number=60;
    var _flame3:Number=50;
    var _flame4:Number=40;
    var _flame5:Number=30;
    var _flame6:Number=20;
    var _flame7:Number=10;
    var _flame8:Number=0;

    public function Sound2Visual() {
      snd=new Sound  ;
      req=new URLRequest("MySound.mp3");
      snd.load(req);
      channel=snd.play();

      _mc = new MVI_0419_0000();
      _mc.y = 0;
      _mc.y = 200;
      addChild(_mc);
      _mc1 = new MVI_0419_0000();
      _mc1.x = 133;
      _mc1.y = 200;
      addChild(_mc1);
      _mc2 = new MVI_0419_0000();
      _mc2.x = 266;
      _mc2.y = 200;
      addChild(_mc2);
      _mc3 = new MVI_0419_0000();
      _mc3.x = 0;
      _mc3.y = 300;
      addChild(_mc3);
      _mc4 = new MVI_0419_0000();
      _mc4.x = 133;
      _mc4.y = 300;
      addChild(_mc4);
      _mc5 = new MVI_0419_0000();
      _mc5.x = 266;
      _mc5.y = 300;
      addChild(_mc5);
      _mc6 = new MVI_0419_0000();
      _mc6.x = 0;
      _mc6.y = 400;
      addChild(_mc6);
      _mc7 = new MVI_0419_0000();
      _mc7.x = 133;
      _mc7.y = 400;
      addChild(_mc7);
      _mc8 = new MVI_0419_0000();
      _mc8.x = 266;
      _mc8.y = 400;
      addChild(_mc8);

      addEventListener(Event.ENTER_FRAME,onEnterFrame);
      snd.addEventListener(Event.SOUND_COMPLETE,onPlaybackComplete);

    }
    function onEnterFrame(event:Event):void {
      bytes=new ByteArray  ;

      SoundMixer.computeSpectrum(bytes,false,0);

      g=this.graphics;
      g.clear();
      g.lineStyle(1,0x6600CC,1);

      var n:Number=0;

      // left channel
      for (var i:int=0; i < CHANNEL_LENGTH; i++) {
        n=bytes.readFloat() * PLOT_HEIGHT;
        //trace(n);

        //0~840ã¾ã§


        if (i % 3 == 0) {
          g.moveTo(i * 2 / 2,PLOT_HEIGHT);
          g.lineTo(i * 2 / 2,PLOT_HEIGHT - n);
        }
      }

      _flame0 = _flame0 + Math.abs(Math.floor(n/10))+1;
      if(_flame0 > _maxFrame){
        _flame0 = 0;
      }
      _flame1 = _flame1 + Math.abs(Math.floor(n/10))+1;
      if(_flame1 > _maxFrame){
        _flame1 = 0;
      }
      _flame2 = _flame2 + Math.abs(Math.floor(n/10))+1;
      if(_flame2 > _maxFrame){
        _flame2 = 0;
      }
      _flame3 = _flame3 + Math.abs(Math.floor(n/10))+1;
      if(_flame3 > _maxFrame){
        _flame3 = 0;
      }
      _flame4 = _flame4 + Math.abs(Math.floor(n/10))+1;
      if(_flame4 > _maxFrame){
        _flame4 = 0;
      }
      _flame5 = _flame5 + Math.abs(Math.floor(n/10))+1;
      if(_flame5 > _maxFrame){
        _flame5 = 0;
      }
      _flame6 = _flame6 + Math.abs(Math.floor(n/10))+1;
      if(_flame6 > _maxFrame){
        _flame6 = 0;
      }
      _flame7 = _flame7 + Math.abs(Math.floor(n/10))+1;
      if(_flame7 > _maxFrame){
        _flame7 = 0;
      }
      _flame8 = _flame8 + Math.abs(Math.floor(n/10))+1;
      if(_flame8 > _maxFrame){
        _flame8 = 0;
      }




      _mc.gotoAndStop(_flame0);
      _mc1.gotoAndStop(_flame1);
      _mc2.gotoAndStop(_flame2);
      _mc3.gotoAndStop(_flame3);
      _mc4.gotoAndStop(_flame4);
      _mc5.gotoAndStop(_flame5);
      _mc6.gotoAndStop(_flame6);
      _mc7.gotoAndStop(_flame7);
      _mc8.gotoAndStop(_flame8);


      // right channel
      g.lineStyle(1,0xCC0066,1);

      for (i=CHANNEL_LENGTH; i > 0; i--) {
        n=bytes.readFloat() * PLOT_HEIGHT;

        if (i % 3 == 0) {
          g.moveTo(i * 2 / 2 + 200,PLOT_HEIGHT);
          g.lineTo(i * 2 / 2 + 200,PLOT_HEIGHT - n);
        }
      }
    }

    function onPlaybackComplete(event:Event) {
      removeEventListener(Event.ENTER_FRAME,onEnterFrame);
    }
  }
}
