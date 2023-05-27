
# Spoofer with Keyauth System




## Tutorial

Create account on https://keyauth.cc 

```bash
Replace this in main.cpp for your aplication name , ownerid , secret


std::string name = ""; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = ""; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = ""; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting

If you replace this , bulid spoofer and have fun!

```
    
## Authors

- [@flackkdev](https://www.github.com/flackkdev)


## Support
If you have problem write dm on discord to Flack#6666

## Preview

![App Screenshot](https://cdn.discordapp.com/attachments/1063909240579833898/1112058911818797167/image.png)

![App Screenshot](https://cdn.discordapp.com/attachments/1063909240579833898/1112058861294194799/image.png)




## Based on


- [@SpeedyThePaster](https://github.com/SpeedyThePaster/CFX-Bypass)

