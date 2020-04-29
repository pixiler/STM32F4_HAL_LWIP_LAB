/*
 * MQTTInterface.h
 *
 *  Created on: 2020. 4. 29.
 *      Author: jihoo
 */

#ifndef __MQTT_INTERFACE_H_
#define __MQTT_INTERFACE_H_

typedef struct Timer Timer;

struct Timer {
	unsigned long systick_period;
	unsigned long end_time;
};

typedef struct Network Network;

struct Network
{
	struct netconn *conn;
	struct netbuf *buf;
	int offset;

	int (*mqttread) (Network*, unsigned char*, int, int);
	int (*mqttwrite) (Network*, unsigned char*, int, int);
	void (*disconnect) (Network*);
};

void InitTimer(Timer*);

char TimerIsExpired(Timer*);
void TimerCountdownMS(Timer*, unsigned int);
void TimerCountdown(Timer*, unsigned int);
int TimerLeftMS(Timer*);

int net_read(Network*, unsigned char*, int, int);
int net_write(Network*, unsigned char*, int, int);
void net_disconnect(Network*);
void NewNetwork(Network*);

int ConnectNetwork(Network*, char*, int);

#endif
