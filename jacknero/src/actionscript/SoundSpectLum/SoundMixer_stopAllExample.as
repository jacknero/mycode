package {
  import flash.display.Sprite;
  import flash.net.URLRequest;
  import flash.media.Sound;
  import flash.media.SoundLoaderContext;
  import flash.media.SoundChannel;
  import flash.media.SoundMixer;
  import flash.text.TextField;
  import flash.text.TextFieldAutoSize;
  import flash.events.MouseEvent;
  import flash.events.IOErrorEvent;

  public class SoundMixer_stopAllExample extends Sprite  {
    private var firstSound:Sound = new Sound();
    private var secondSound:Sound = new Sound();
    private var muteButton:TextField = new TextField();
    private var channel1:SoundChannel = new SoundChannel();

    public function SoundMixer_stopAllExample() {
      firstSound.load(new URLRequest("mySound.mp3"));
      secondSound.load(new URLRequest("http://av.adobe.com/podcast/csbu_dev_podcast_epi_2.mp3"));

      firstSound.addEventListener(IOErrorEvent.IO_ERROR, firstSoundErrorHandler);
      secondSound.addEventListener(IOErrorEvent.IO_ERROR, secondSoundErrorHandler);

      channel1 = firstSound.play();
      secondSound.play();

      muteButton.autoSize = TextFieldAutoSize.LEFT;
      muteButton.border = true;
      muteButton.background = true;
      muteButton.text = "MUTE";

      muteButton.addEventListener(MouseEvent.CLICK, muteButtonClickHandler);         

      this.addChild(muteButton);
    }

    private function muteButtonClickHandler(event:MouseEvent):void {

      if(muteButton.text == "MUTE") {        

        if(SoundMixer.areSoundsInaccessible() == false) {
          SoundMixer.stopAll();
          muteButton.text = "click to play only one of sound.";
        }
        else {
          muteButton.text = "The sounds are not accessible.";
        }
      }
      else {
        firstSound.play();        
        muteButton.text = "MUTE";
      }
    } 

    private function firstSoundErrorHandler(errorEvent:IOErrorEvent):void {
      trace(errorEvent.text);
    }

    private function secondSoundErrorHandler(errorEvent:IOErrorEvent):void {
      trace(errorEvent.text);
    }
  }
}

