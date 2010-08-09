
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "mapper_internal.h"
#include "types_internal.h"
#include <mapper/mapper.h>

mapper_signal msig_float(int length, const char *name,
                         const char *unit, float minimum,
                         float maximum, float *value,
                         mapper_signal_handler *handler, void *user_data)
{
    mapper_signal sig =
        (mapper_signal) calloc(1, sizeof(struct _mapper_signal));
    sig->type = 'f';
    sig->length = length;
    assert(length >= 1);
    assert(name != 0);
    sig->name = strdup(name);
    if (unit)
        sig->unit = strdup(unit);
    sig->value = (mapper_signal_value_t *) value;

    if (minimum != INFINITY && minimum != -INFINITY) {
        sig->minimum = (mapper_signal_value_t *)
            malloc(sizeof(mapper_signal_value_t));
        sig->minimum->f = minimum;
    }

    if (maximum != INFINITY && maximum != -INFINITY) {
        sig->maximum = (mapper_signal_value_t*) malloc(sizeof(mapper_signal_value_t));
        sig->maximum->f = maximum;
    }

    sig->handler = handler;
    sig->user_data = user_data;
    return sig;
}

void msig_update_scalar(mapper_signal sig, mapper_signal_value_t value)
{
    mdev_route_signal(sig->device, sig, &value);
}

void msig_update(mapper_signal sig, mapper_signal_value_t *value)
{
    mdev_route_signal(sig->device, sig, value);
}

void mval_add_to_message(lo_message m, mapper_signal sig,
                         mapper_signal_value_t *value)
{
    switch (sig->type) {
    case 'f':
        lo_message_add_float(m, value->f);
        break;
    case 'd':
        lo_message_add_double(m, value->d);
        break;
    case 'i':
        lo_message_add_int32(m, value->i32);
        break;
    default:
        // Unknown signal type
        assert(0);
        break;
    }
}

int msig_full_name(mapper_signal sig, char *name, int len)
{
    const char *mdname = mdev_name(sig->device);
    if (!mdname)
        return 0;

    int mdlen = strlen(mdname);
    if (mdlen >= len)
        return 0;
    if ((mdlen + strlen(sig->name)) > len)
        return 0;

    strncpy(name, mdname, len);
    strncat(name, sig->name, len);
    return strlen(name);
}
