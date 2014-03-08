/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "illusions/illusions.h"

#include "audio/audiostream.h"
#include "common/config-manager.h"
#include "common/debug-channels.h"
#include "common/error.h"
#include "common/fs.h"
#include "common/timer.h"
#include "engines/util.h"
#include "graphics/cursorman.h"
#include "graphics/font.h"
#include "graphics/fontman.h"
#include "graphics/palette.h"
#include "graphics/surface.h"

namespace Illusions {

IllusionsEngine::IllusionsEngine(OSystem *syst, const ADGameDescription *gd) :
	Engine(syst), _gameDescription(gd) {
	
	_random = new Common::RandomSource("illusions");
	
	Engine::syncSoundSettings();

}

IllusionsEngine::~IllusionsEngine() {

	delete _random;

}

Common::Error IllusionsEngine::run() {

	Graphics::PixelFormat pixelFormat16(2, 5, 6, 5, 0, 11, 5, 0, 0);
	initGraphics(640, 480, true, &pixelFormat16);

	while (!shouldQuit()) {
		updateEvents();
	}
	
	return Common::kNoError;
}

bool IllusionsEngine::hasFeature(EngineFeature f) const {
	return
		false;
		/*
		(f == kSupportsRTL) ||
		(f == kSupportsLoadingDuringRuntime) ||
		(f == kSupportsSavingDuringRuntime);
		*/
}

void IllusionsEngine::updateEvents() {
	Common::Event event;

	while (_eventMan->pollEvent(event)) {
		switch (event.type) {
		case Common::EVENT_KEYDOWN:
			break;
		case Common::EVENT_KEYUP:
			break;
		case Common::EVENT_MOUSEMOVE:
  			break;
		case Common::EVENT_LBUTTONDOWN:
  			break;
		case Common::EVENT_LBUTTONUP:
  			break;
		case Common::EVENT_RBUTTONDOWN:
  			break;
		case Common::EVENT_RBUTTONUP:
  			break;
		case Common::EVENT_QUIT:
			quitGame();
			break;
		default:
			break;
		}
	}
}

} // End of namespace Illusions