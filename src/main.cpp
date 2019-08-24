#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <Secret.h>

const char *server = "api.thingspeak.com";

int retries = 0;
DHT dht(2, DHT22);

void ConnectToWifi()
{
	Serial.println("");
	Serial.print("Connecting to ");
	Serial.println(SSID);
	WiFi.persistent(false);
	WiFi.begin(SSID, PSK);
	while ((WiFi.status() != WL_CONNECTED) && (retries < 10))
	{
		retries++;
		delay(1000);
		Serial.print(".");
	}

	if (WiFi.status() == WL_CONNECTED)
	{
		Serial.println("");
		Serial.print("Connected to AP: ");
		Serial.println(SSID);
		Serial.print("Signal: ");
		Serial.print(WiFi.RSSI());
		Serial.println(" dBm");
		Serial.print("IP address: ");
		Serial.println(WiFi.localIP());
		Serial.print("Mac: ");
		Serial.println(WiFi.macAddress());
		Serial.println("");
	}
	else
	{
		Serial.println("");
		Serial.println("NOT connected to AP: ");
		Serial.println(SSID);
		Serial.println("");
	}
}

void setup()
{
	Serial.begin(115200);
	dht.begin();
	Serial.println("");
	Serial.println("START");
	ConnectToWifi();
}

void SendTeperature(float temp, float hum)
{
	WiFiClient client;

	if (client.connect(server, 80))
	{
		Serial.println("Thingspeak connected ");

		ThingSpeak.begin(client);
		ThingSpeak.setField(1, temp);
		ThingSpeak.setField(2, hum);
		ThingSpeak.writeFields(ChannelNumber, ApiKey);
	}
	else
	{
		Serial.println("Thingspeak NOT connected");
	}

	client.stop();
}

void loop()
{
	delay(100);
	float temperature = dht.readTemperature();
	delay(100);
	float humidity = dht.readHumidity();

	Serial.print("Temperature: ");
	Serial.println(temperature);
	Serial.print("Humidity: ");
	Serial.println(humidity);

	SendTeperature(temperature, humidity);

	Serial.print("ESP8266 in sleep mode on ");
	Serial.print(DeepSleepTime / 1e6);
	Serial.print(" seconds");
	ESP.deepSleep(DeepSleepTime, WAKE_RF_DEFAULT);
}