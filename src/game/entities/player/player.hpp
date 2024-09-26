#ifndef PLAYER_H
#define PLAYER_H
#include <entities/actor.hpp>

struct HeldWeaponData {
    float reload_progress;
    int weapon_id;
};

class Player: public Actor {
public:
    ParticleSystem run_particles;
    CameraComponent* camera_comp;
    Label nametag;
    int look_dir;
    int weapon_equped_index;
    int weapon_number;
    std::vector<HeldWeaponData> weapons;

    Player(std::string username = "[unnamed]");
    void process(float delta);
    void private_process(float delta);
    void swap_weapon();
    
    static void init_weapons();
    static void init_projectiles();

    std::pair<EntitySyncPacket*, size_t> get_init_packet();
};

#endif