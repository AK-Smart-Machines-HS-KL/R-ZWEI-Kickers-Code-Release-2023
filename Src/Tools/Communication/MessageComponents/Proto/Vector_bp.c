// Code generated by bitproto. DO NOT EDIT.

#include "bitproto.h"
#include "Vector_bp.h"

void BpFieldDescriptorsInitVector2(struct Vector2 *m, struct BpMessageFieldDescriptor *fds) {
    fds[0] = BpMessageFieldDescriptor((void *)&(m->x), BpInt(14, sizeof(int16_t)), "x");
    fds[1] = BpMessageFieldDescriptor((void *)&(m->y), BpInt(14, sizeof(int16_t)), "y");
}

void BpXXXProcessVector2(void *data, struct BpProcessorContext *ctx) {
    struct Vector2 *m = (struct Vector2 *)(data);
    struct BpMessageFieldDescriptor field_descriptors[2];
    BpFieldDescriptorsInitVector2(m, field_descriptors);
    struct BpMessageDescriptor descriptor = BpMessageDescriptor(false, 2, 28, field_descriptors);
    BpEndecodeMessage(&descriptor, ctx, data);
}

void BpXXXJsonFormatVector2(void *data, struct BpJsonFormatContext *ctx) {
    struct Vector2 *m = (struct Vector2 *)(data);
    struct BpMessageFieldDescriptor field_descriptors[2];
    BpFieldDescriptorsInitVector2(m, field_descriptors);
    struct BpMessageDescriptor descriptor = BpMessageDescriptor(false, 2, 28, field_descriptors);
    BpJsonFormatMessage(&descriptor, ctx, data);
}

int EncodeVector2(struct Vector2 *m, unsigned char *s) {
    struct BpProcessorContext ctx = BpProcessorContext(true, s);
    BpXXXProcessVector2((void *)m, &ctx);
    return 0;
}

int DecodeVector2(struct Vector2 *m, unsigned char *s) {
    struct BpProcessorContext ctx = BpProcessorContext(false, s);
    BpXXXProcessVector2((void *)m, &ctx);
    return 0;
}

int JsonVector2(struct Vector2 *m, char *s) {
    struct BpJsonFormatContext ctx = BpJsonFormatContext(s);
    BpXXXJsonFormatVector2((void *)m, &ctx);
    return ctx.n;
}

void BpFieldDescriptorsInitAngle(struct Angle *m, struct BpMessageFieldDescriptor *fds) {
    fds[0] = BpMessageFieldDescriptor((void *)&(m->milli_radians), BpInt(12, sizeof(int16_t)), "milli_radians");
}

void BpXXXProcessAngle(void *data, struct BpProcessorContext *ctx) {
    struct Angle *m = (struct Angle *)(data);
    struct BpMessageFieldDescriptor field_descriptors[1];
    BpFieldDescriptorsInitAngle(m, field_descriptors);
    struct BpMessageDescriptor descriptor = BpMessageDescriptor(false, 1, 12, field_descriptors);
    BpEndecodeMessage(&descriptor, ctx, data);
}

void BpXXXJsonFormatAngle(void *data, struct BpJsonFormatContext *ctx) {
    struct Angle *m = (struct Angle *)(data);
    struct BpMessageFieldDescriptor field_descriptors[1];
    BpFieldDescriptorsInitAngle(m, field_descriptors);
    struct BpMessageDescriptor descriptor = BpMessageDescriptor(false, 1, 12, field_descriptors);
    BpJsonFormatMessage(&descriptor, ctx, data);
}

int EncodeAngle(struct Angle *m, unsigned char *s) {
    struct BpProcessorContext ctx = BpProcessorContext(true, s);
    BpXXXProcessAngle((void *)m, &ctx);
    return 0;
}

int DecodeAngle(struct Angle *m, unsigned char *s) {
    struct BpProcessorContext ctx = BpProcessorContext(false, s);
    BpXXXProcessAngle((void *)m, &ctx);
    return 0;
}

int JsonAngle(struct Angle *m, char *s) {
    struct BpJsonFormatContext ctx = BpJsonFormatContext(s);
    BpXXXJsonFormatAngle((void *)m, &ctx);
    return ctx.n;
}

void BpFieldDescriptorsInitPose2(struct Pose2 *m, struct BpMessageFieldDescriptor *fds) {
    fds[0] = BpMessageFieldDescriptor((void *)&(m->translation), BpMessage(28, sizeof(struct Vector2), BpXXXProcessVector2, BpXXXJsonFormatVector2), "translation");
    fds[1] = BpMessageFieldDescriptor((void *)&(m->rotation), BpMessage(12, sizeof(struct Angle), BpXXXProcessAngle, BpXXXJsonFormatAngle), "rotation");
}

void BpXXXProcessPose2(void *data, struct BpProcessorContext *ctx) {
    struct Pose2 *m = (struct Pose2 *)(data);
    struct BpMessageFieldDescriptor field_descriptors[2];
    BpFieldDescriptorsInitPose2(m, field_descriptors);
    struct BpMessageDescriptor descriptor = BpMessageDescriptor(false, 2, 40, field_descriptors);
    BpEndecodeMessage(&descriptor, ctx, data);
}

void BpXXXJsonFormatPose2(void *data, struct BpJsonFormatContext *ctx) {
    struct Pose2 *m = (struct Pose2 *)(data);
    struct BpMessageFieldDescriptor field_descriptors[2];
    BpFieldDescriptorsInitPose2(m, field_descriptors);
    struct BpMessageDescriptor descriptor = BpMessageDescriptor(false, 2, 40, field_descriptors);
    BpJsonFormatMessage(&descriptor, ctx, data);
}

int EncodePose2(struct Pose2 *m, unsigned char *s) {
    struct BpProcessorContext ctx = BpProcessorContext(true, s);
    BpXXXProcessPose2((void *)m, &ctx);
    return 0;
}

int DecodePose2(struct Pose2 *m, unsigned char *s) {
    struct BpProcessorContext ctx = BpProcessorContext(false, s);
    BpXXXProcessPose2((void *)m, &ctx);
    return 0;
}

int JsonPose2(struct Pose2 *m, char *s) {
    struct BpJsonFormatContext ctx = BpJsonFormatContext(s);
    BpXXXJsonFormatPose2((void *)m, &ctx);
    return ctx.n;
}