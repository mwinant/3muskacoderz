#include "sound.h"


Sound::Sound(const SoundBuffer& buffer){
    mSound.setBuffer(buffer.getBuffer());
   
}
