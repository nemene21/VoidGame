all: Build.exe

object_files/commands.o: ../src/framework/commands.cpp ../src/framework/commands.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/commands.cpp -o $(@)

object_files/component.o: ../src/framework/component.cpp ../src/framework/component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/component.cpp -o $(@)

object_files/animation_component.o: ../src/framework/components/animation_component.cpp ../src/framework/components/animation_component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/animation_component.cpp -o $(@)

object_files/area_component.o: ../src/framework/components/area_component.cpp ../src/framework/components/area_component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/area_component.cpp -o $(@)

object_files/camera_component.o: ../src/framework/components/camera_component.cpp ../src/framework/components/camera_component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/camera_component.cpp -o $(@)

object_files/collider_component.o: ../src/framework/components/collider_component.cpp ../src/framework/components/collider_component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/collider_component.cpp -o $(@)

object_files/health_component.o: ../src/framework/components/health_component.cpp ../src/framework/components/health_component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/health_component.cpp -o $(@)

object_files/state_component.o: ../src/framework/components/state_component.cpp ../src/framework/components/state_component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/state_component.cpp -o $(@)

object_files/stats.o: ../src/framework/components/stats.cpp ../src/framework/components/stats.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/stats.cpp -o $(@)

object_files/timer_component.o: ../src/framework/components/timer_component.cpp ../src/framework/components/timer_component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/timer_component.cpp -o $(@)

object_files/transform_component.o: ../src/framework/components/transform_component.cpp ../src/framework/components/transform_component.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/transform_component.cpp -o $(@)

object_files/tilemap_entity.o: ../src/framework/entities/tilemap_entity.cpp ../src/framework/entities/tilemap_entity.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/entities/tilemap_entity.cpp -o $(@)

object_files/tilemap_renderer.o: ../src/framework/entities/tilemap_renderer.cpp ../src/framework/entities/tilemap_renderer.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/entities/tilemap_renderer.cpp -o $(@)

object_files/entity.o: ../src/framework/entity.cpp ../src/framework/entity.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/entity.cpp -o $(@)

object_files/framework.o: ../src/framework/framework.cpp ../src/framework/framework.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/framework.cpp -o $(@)

object_files/imgui.o: ../src/framework/imgui/imgui.cpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/imgui/imgui.cpp -o $(@)

object_files/imgui_demo.o: ../src/framework/imgui/imgui_demo.cpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/imgui/imgui_demo.cpp -o $(@)

object_files/imgui_draw.o: ../src/framework/imgui/imgui_draw.cpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/imgui/imgui_draw.cpp -o $(@)

object_files/imgui_tables.o: ../src/framework/imgui/imgui_tables.cpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/imgui/imgui_tables.cpp -o $(@)

object_files/imgui_widgets.o: ../src/framework/imgui/imgui_widgets.cpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/imgui/imgui_widgets.cpp -o $(@)

object_files/rlImGui.o: ../src/framework/imgui/rlImGui.cpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/imgui/rlImGui.cpp -o $(@)

object_files/input.o: ../src/framework/input.cpp ../src/framework/input.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/input.cpp -o $(@)

object_files/misc.o: ../src/framework/misc.cpp ../src/framework/misc.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/misc.cpp -o $(@)

object_files/networking.o: ../src/framework/networking/networking.cpp ../src/framework/networking/networking.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/networking/networking.cpp -o $(@)

object_files/packets.o: ../src/framework/networking/packets.cpp ../src/framework/networking/packets.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/networking/packets.cpp -o $(@)

object_files/audio.o: ../src/framework/objects/audio.cpp ../src/framework/objects/audio.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/audio.cpp -o $(@)

object_files/drawables.o: ../src/framework/objects/drawables.cpp ../src/framework/objects/drawables.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/drawables.cpp -o $(@)

object_files/label.o: ../src/framework/objects/label.cpp ../src/framework/objects/label.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/label.cpp -o $(@)

object_files/particles.o: ../src/framework/objects/particles.cpp ../src/framework/objects/particles.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/particles.cpp -o $(@)

object_files/progress_bar.o: ../src/framework/objects/progress_bar.cpp ../src/framework/objects/progress_bar.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/progress_bar.cpp -o $(@)

object_files/sprites.o: ../src/framework/objects/sprites.cpp ../src/framework/objects/sprites.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/sprites.cpp -o $(@)

object_files/spritesheet.o: ../src/framework/objects/spritesheet.cpp ../src/framework/objects/spritesheet.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/spritesheet.cpp -o $(@)

object_files/trails.o: ../src/framework/objects/trails.cpp ../src/framework/objects/trails.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/trails.cpp -o $(@)

object_files/ui_drawables.o: ../src/framework/objects/ui_drawables.cpp ../src/framework/objects/ui_drawables.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/ui_drawables.cpp -o $(@)

object_files/rich_presence.o: ../src/framework/rich_presence.cpp ../src/framework/rich_presence.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/rich_presence.cpp -o $(@)

object_files/scene.o: ../src/framework/scene.cpp ../src/framework/scene.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/scene.cpp -o $(@)

object_files/signal.o: ../src/framework/signal.cpp ../src/framework/signal.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/signal.cpp -o $(@)

object_files/actor.o: ../src/game/entities/actor.cpp ../src/game/entities/actor.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/actor.cpp -o $(@)

object_files/background.o: ../src/game/entities/background.cpp ../src/game/entities/background.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/background.cpp -o $(@)

object_files/endgate.o: ../src/game/entities/endgate.cpp ../src/game/entities/endgate.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/endgate.cpp -o $(@)

object_files/chaser.o: ../src/game/entities/enemies/chaser/chaser.cpp ../src/game/entities/enemies/chaser/chaser.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/enemies/chaser/chaser.cpp -o $(@)

object_files/enemy.o: ../src/game/entities/enemies/enemy.cpp ../src/game/entities/enemies/enemy.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/enemies/enemy.cpp -o $(@)

object_files/player.o: ../src/game/entities/player/player.cpp ../src/game/entities/player/player.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/player/player.cpp -o $(@)

object_files/player_projectile.o: ../src/game/entities/player_projectiles/player_projectile.cpp ../src/game/entities/player_projectiles/player_projectile.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/player_projectiles/player_projectile.cpp -o $(@)

object_files/button.o: ../src/game/entities/UI/button/button.cpp ../src/game/entities/UI/button/button.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/UI/button/button.cpp -o $(@)

object_files/focusable.o: ../src/game/entities/UI/focusable.cpp ../src/game/entities/UI/focusable.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/UI/focusable.cpp -o $(@)

object_files/game_start_ui.o: ../src/game/entities/UI/game_start_ui.cpp ../src/game/entities/UI/game_start_ui.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/UI/game_start_ui.cpp -o $(@)

object_files/input_field.o: ../src/game/entities/UI/input_field/input_field.cpp ../src/game/entities/UI/input_field/input_field.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/UI/input_field/input_field.cpp -o $(@)

object_files/gun.o: ../src/game/entities/weapons/guns/gun.cpp ../src/game/entities/weapons/guns/gun.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/weapons/guns/gun.cpp -o $(@)

object_files/projectile_weapon.o: ../src/game/entities/weapons/projectile_weapon.cpp ../src/game/entities/weapons/projectile_weapon.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/weapons/projectile_weapon.cpp -o $(@)

object_files/weapon.o: ../src/game/entities/weapons/weapon.cpp ../src/game/entities/weapons/weapon.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/entities/weapons/weapon.cpp -o $(@)

object_files/game.o: ../src/game/scenes/game.cpp ../src/game/scenes/game.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/scenes/game.cpp -o $(@)

object_files/menu.o: ../src/game/scenes/menu.cpp ../src/game/scenes/menu.hpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/game/scenes/menu.cpp -o $(@)

object_files/main.o: ../src/main.cpp
	g++ -g -g -O1 -Wall -Wno-missing-braces -I../src/game/ -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/main.cpp -o $(@)

Build.exe: object_files/commands.o object_files/component.o object_files/animation_component.o object_files/area_component.o object_files/camera_component.o object_files/collider_component.o object_files/health_component.o object_files/state_component.o object_files/stats.o object_files/timer_component.o object_files/transform_component.o object_files/tilemap_entity.o object_files/tilemap_renderer.o object_files/entity.o object_files/framework.o object_files/imgui.o object_files/imgui_demo.o object_files/imgui_draw.o object_files/imgui_tables.o object_files/imgui_widgets.o object_files/rlImGui.o object_files/input.o object_files/misc.o object_files/networking.o object_files/packets.o object_files/audio.o object_files/drawables.o object_files/label.o object_files/particles.o object_files/progress_bar.o object_files/sprites.o object_files/spritesheet.o object_files/trails.o object_files/ui_drawables.o object_files/rich_presence.o object_files/scene.o object_files/signal.o object_files/actor.o object_files/background.o object_files/endgate.o object_files/chaser.o object_files/enemy.o object_files/player.o object_files/player_projectile.o object_files/button.o object_files/focusable.o object_files/game_start_ui.o object_files/input_field.o object_files/gun.o object_files/projectile_weapon.o object_files/weapon.o object_files/game.o object_files/menu.o object_files/main.o 
	g++ -g -o Build.exe object_files/commands.o object_files/component.o object_files/animation_component.o object_files/area_component.o object_files/camera_component.o object_files/collider_component.o object_files/health_component.o object_files/state_component.o object_files/stats.o object_files/timer_component.o object_files/transform_component.o object_files/tilemap_entity.o object_files/tilemap_renderer.o object_files/entity.o object_files/framework.o object_files/imgui.o object_files/imgui_demo.o object_files/imgui_draw.o object_files/imgui_tables.o object_files/imgui_widgets.o object_files/rlImGui.o object_files/input.o object_files/misc.o object_files/networking.o object_files/packets.o object_files/audio.o object_files/drawables.o object_files/label.o object_files/particles.o object_files/progress_bar.o object_files/sprites.o object_files/spritesheet.o object_files/trails.o object_files/ui_drawables.o object_files/rich_presence.o object_files/scene.o object_files/signal.o object_files/actor.o object_files/background.o object_files/endgate.o object_files/chaser.o object_files/enemy.o object_files/player.o object_files/player_projectile.o object_files/button.o object_files/focusable.o object_files/game_start_ui.o object_files/input_field.o object_files/gun.o object_files/projectile_weapon.o object_files/weapon.o object_files/game.o object_files/menu.o object_files/main.o -L../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -ldiscord-rpc -lenet64 -lws2_32 -lwinmm -static

.PHONY: clean
clean:
	del /S /Q object_files\commands.o
	del /S /Q object_files\component.o
	del /S /Q object_files\animation_component.o
	del /S /Q object_files\area_component.o
	del /S /Q object_files\camera_component.o
	del /S /Q object_files\collider_component.o
	del /S /Q object_files\health_component.o
	del /S /Q object_files\state_component.o
	del /S /Q object_files\stats.o
	del /S /Q object_files\timer_component.o
	del /S /Q object_files\transform_component.o
	del /S /Q object_files\tilemap_entity.o
	del /S /Q object_files\tilemap_renderer.o
	del /S /Q object_files\entity.o
	del /S /Q object_files\framework.o
	del /S /Q object_files\imgui.o
	del /S /Q object_files\imgui_demo.o
	del /S /Q object_files\imgui_draw.o
	del /S /Q object_files\imgui_tables.o
	del /S /Q object_files\imgui_widgets.o
	del /S /Q object_files\rlImGui.o
	del /S /Q object_files\input.o
	del /S /Q object_files\misc.o
	del /S /Q object_files\networking.o
	del /S /Q object_files\packets.o
	del /S /Q object_files\audio.o
	del /S /Q object_files\drawables.o
	del /S /Q object_files\label.o
	del /S /Q object_files\particles.o
	del /S /Q object_files\progress_bar.o
	del /S /Q object_files\sprites.o
	del /S /Q object_files\spritesheet.o
	del /S /Q object_files\trails.o
	del /S /Q object_files\ui_drawables.o
	del /S /Q object_files\rich_presence.o
	del /S /Q object_files\scene.o
	del /S /Q object_files\signal.o
	del /S /Q object_files\actor.o
	del /S /Q object_files\background.o
	del /S /Q object_files\endgate.o
	del /S /Q object_files\chaser.o
	del /S /Q object_files\enemy.o
	del /S /Q object_files\player.o
	del /S /Q object_files\player_projectile.o
	del /S /Q object_files\button.o
	del /S /Q object_files\focusable.o
	del /S /Q object_files\game_start_ui.o
	del /S /Q object_files\input_field.o
	del /S /Q object_files\gun.o
	del /S /Q object_files\projectile_weapon.o
	del /S /Q object_files\weapon.o
	del /S /Q object_files\game.o
	del /S /Q object_files\menu.o
	del /S /Q object_files\main.o
