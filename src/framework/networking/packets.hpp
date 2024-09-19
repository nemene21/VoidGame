#ifndef PACKETS_H
#define PACKETS_H
#include <iostream>
#include <cstdint>
#include <functional>
#include <raylib.h>

enum class EntityType: uint16_t {
    PLAYER,
    GUN,
    PLAYER_PROJECTILE,
    PARTICLE_SYSTEM,
    CHASER_ENEMY,
    COUNT,
};

enum class PacketType: uint8_t  {
    LOG,
    ENTITY_SYNC,
    ENTITY_NUKE,
    COMPONENT_UPDATE,
    GENERATION,
    COUNT,
};

struct Packet {
    PacketType type;
    bool global;
};

struct LogPacket: public Packet {
    char message[256];
};

// Component packets
struct ComponentUpdatePacket: public Packet {
    uint32_t entity_id;
    uint8_t  component_type;
};
struct TransformUpdatePacket: public ComponentUpdatePacket {
    Vector2 position, velocity, scale;
    float angle;
};
struct AnimationUpdatePacket: public ComponentUpdatePacket {
    bool paused;
    int8_t direction;
    float playback_speed;
    char animation_name[16];
};

struct EntitySyncPacket: public Packet {
    EntityType entity_type;
    uint32_t id;
    bool owned;
};
struct EntityTextureSyncPacket: public EntitySyncPacket {
    char texture[64];
};
struct EntityParticleSyncPacket: public EntitySyncPacket {
    int8_t z_coord;
    char system[64];
};
struct EntityPlayerSyncPacket: public EntitySyncPacket {
    char username[16];
};
struct EntityNukePacket: public Packet {
    uint32_t id;
};

struct GenerationPacket: public Packet {
    uint64_t seed;
};

extern std::function<void(Packet*)> unpackers[(int)PacketType::COUNT];
namespace Packets {
    void init();
}

#endif