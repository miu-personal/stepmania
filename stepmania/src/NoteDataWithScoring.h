#ifndef NOTEDATAWITHSCORING_H
#define NOTEDATAWITHSCORING_H
/*
-----------------------------------------------------------------------------
 Class: NoteDataWithScoring

 Desc: NoteData with scores for each TapNote and HoldNote

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/

#include "GameConstantsAndTypes.h"
#include "NoteData.h"

class NoteDataWithScoring : public NoteData
{
public:
	// maintain this extra data in addition to the NoteData
	TapNoteScore	m_TapNoteScores[MAX_NOTE_TRACKS][MAX_TAP_NOTE_ROWS];

	NoteDataWithScoring();
	void Init(int taps=0, int holds=0);

	vector<HoldNoteScore> m_HoldNoteScores;
	/* 1.0 means this HoldNote has full life.
	 * 0.0 means this HoldNote is dead
	 * When this value hits 0.0 for the first time, m_HoldScore becomes HSS_NG.
	 * If the life is > 0.0 when the HoldNote ends, then m_HoldScore becomes HSS_OK. */
	vector<float>	m_fHoldNoteLife;

	// statistics
	int GetNumTapNotesWithScore( TapNoteScore tns, const float fStartBeat = 0, const float fEndBeat = MAX_BEATS );
	int GetNumDoublesWithScore( TapNoteScore tns, const float fStartBeat = 0, const float fEndBeat = MAX_BEATS );
	int GetNumHoldNotesWithScore( HoldNoteScore hns, const float fStartBeat = 0, const float fEndBeat = MAX_BEATS );

	TapNoteScore GetTapNoteScore(int track, int row) const
	{
		return m_TapNoteScores[track][row];
	}
	void SetTapNoteScore(int track, int row, TapNoteScore tns)
	{
		m_TapNoteScores[track][row] = tns;
	}

	bool IsRowComplete( int index );

	float GetActualRadarValue( RadarCategory rv, float fSongSeconds );
	float GetActualStreamRadarValue( float fSongSeconds );
	float GetActualVoltageRadarValue( float fSongSeconds );
	float GetActualAirRadarValue( float fSongSeconds );
	float GetActualFreezeRadarValue( float fSongSeconds );
	float GetActualChaosRadarValue( float fSongSeconds );
};


#endif
