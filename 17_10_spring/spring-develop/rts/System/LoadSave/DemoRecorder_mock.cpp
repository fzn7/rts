// TODO: Substitue CDemoRecorder with your actual class name
void CDemoRecorder::WriteSetupText(const std::string & text){}
void CDemoRecorder::SaveToDemo(const unsigned char * buf, const unsigned int length, const float modGameTime){}
void CDemoRecorder::SetStream(){}
void CDemoRecorder::SetName(const std::string & mapName, const std::string & modName){}
void CDemoRecorder::SetGameID(const unsigned char * buf){}
void CDemoRecorder::SetTime(int gameTime, int wallclockTime){}
void CDemoRecorder::AddNewPlayer(const std::string & name, int playerNum){}
void CDemoRecorder::InitializeStats(int numPlayers, int numTeams){}
void CDemoRecorder::SetPlayerStats(int playerNum, const PlayerStatistics & stats){}
void CDemoRecorder::SetTeamStats(int teamNum, const std::vector<(TeamStatistics)> & stats){}
void CDemoRecorder::SetWinningAllyTeams(const std::vector<(unsigned char)> & winningAllyTeams){}
unsigned int CDemoRecorder::WriteFileHeader(bool updateStreamLength){}
void CDemoRecorder::SetFileHeader(){}
void CDemoRecorder::WritePlayerStats(){}
void CDemoRecorder::WriteTeamStats(){}
void CDemoRecorder::WriteWinnerList(){}
void CDemoRecorder::WriteDemoFile(){}
gzFile CDemoRecorder::file(){}
std::vector<(PlayerStatistics)> CDemoRecorder::playerStats(){}
std::vector<(std::vector<(TeamStatistics)>)> CDemoRecorder::teamStats(){}
std::vector<(unsigned char)> CDemoRecorder::winningAllyTeams(){}
bool CDemoRecorder::isServerDemo(){}
