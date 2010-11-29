/*
 * BSD Telephony Of Mexico "Tormenta" Tone Zone Support 2/22/01
 * 
 * Working with the "Tormenta ISA" Card 
 *
 * Primary Author: Mark Spencer <markster@digium.com>
 * 
 * This information from ITU E.180 Supplement 2.
 * UK information from BT SIN 350 Issue 1.1
 * Helpful reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf
 */

/*
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU Lesser General Public License Version 2.1 as published
 * by the Free Software Foundation. See the LICENSE.LGPL file
 * included with this program for more details.
 *
 * In addition, when this program is distributed with Asterisk in
 * any form that would qualify as a 'combined work' or as a
 * 'derivative work' (but not mere aggregation), you can redistribute
 * and/or modify the combination under the terms of the license
 * provided with that copy of Asterisk, instead of the license
 * terms granted here.
 */

#include "tonezone.h"

struct tone_zone builtin_zones[] =
{
	{ .zone = 0,
	  .country = "us",
	  .description = "United States / North America",
	  .ringcadence = { 2000, 4000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "350+440" },
			{ DAHDI_TONE_BUSY, "480+620/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "440+480/2000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "480+620/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "440/300,0/10000" },
			{ DAHDI_TONE_DIALRECALL, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,0" },
			{ DAHDI_TONE_STUTTER, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 1,
	  .country = "au",
	  .description = "Australia",
	  .ringcadence = {  400, 200, 400, 2000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "413+438" },
			{ DAHDI_TONE_BUSY, "425/375,0/375" },
			{ DAHDI_TONE_RINGTONE, "413+438/400,0/200,413+438/400,0/2000" },
			/* XXX Congestion: Should reduce by 10 db every other cadence XXX */
			{ DAHDI_TONE_CONGESTION, "425/375,0/375,420/375,0/375" },
			{ DAHDI_TONE_CALLWAIT, "425/100,0/200,425/200,0/4400" },
			{ DAHDI_TONE_DIALRECALL, "413+428" },
			{ DAHDI_TONE_RECORDTONE, "!425/1000,!0/15000,425/360,0/15000" },
			{ DAHDI_TONE_INFO, "425/2500,0/500" },
			{ DAHDI_TONE_STUTTER, "413+438/100,0/40" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 2,
	  .country = "fr",
	  .description = "France",
	  .ringcadence = { 1500, 3500 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			/* Dialtone can also be 440+330 */
			{ DAHDI_TONE_DIALTONE, "440" },
			{ DAHDI_TONE_BUSY, "440/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "440/1500,0/3500" },
			/* CONGESTION - not specified */
			{ DAHDI_TONE_CONGESTION, "440/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "440/300,0/10000" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,0" },
			{ DAHDI_TONE_STUTTER, "!440/100,!0/100,!440/100,!0/100,!440/100,!0/100,!440/100,!0/100,!440/100,!0/100,!440/100,!0/100,440" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 3,
	  .country = "nl",
	  .description = "Netherlands",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			/* Most of these 425's can also be 450's */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "425/500,0/9500" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "950/330,1400/330,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "425/500,0/50" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 4,
	  .country = "uk",
	  .description = "United Kingdom",
	  .ringcadence = { 400, 200, 400, 2000 },
	  .tones = {
			/* From British Telecom SIN350 v1.2 */
			{ DAHDI_TONE_DIALTONE, "350+440" },
			{ DAHDI_TONE_BUSY, "400/375,0/375" },
			{ DAHDI_TONE_RINGTONE, "400+450/400,0/200,400+450/400,0/2000" },
			{ DAHDI_TONE_CONGESTION, "400/400,0/350,400/225,0/525" },
			{ DAHDI_TONE_CALLWAIT, "400/100,0/4000" },
			{ DAHDI_TONE_DIALRECALL, "350+440" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/60000" },
			{ DAHDI_TONE_INFO, "950/330,0/15,1400/330,0/15,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "350+440/750,440/750" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 5,
	  .country = "fi",
	  .description = "Finland",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/300,0/300" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "425/150,0/150,425/150,0/8000" },
			{ DAHDI_TONE_DIALRECALL, "425/650,0/25" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "950/650,0/325,950/325,0/30,1400/1300,0/2600" },
			{ DAHDI_TONE_STUTTER, "425/650,0/25" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 6,
	  .country = "es",
	  .description = "Spain",
	  .ringcadence = { 1500, 3000},
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/200,0/200" },
			{ DAHDI_TONE_RINGTONE, "425/1500,0/3000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200,425/200,0/200,425/200,0/600" },
			{ DAHDI_TONE_CALLWAIT, "425/175,0/175,425/175,0/3500" },
			{ DAHDI_TONE_DIALRECALL, "!425/200,!0/200,!425/200,!0/200,!425/200,!0/200,425" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "950/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "425/500,0/50" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 7,
	  .country = "jp",
	  .description = "Japan",
	  .ringcadence = { 1000, 2000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "400" },
			{ DAHDI_TONE_BUSY, "400/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "400+15/1000,0/2000" },
			{ DAHDI_TONE_CONGESTION, "400/500,0/500" },
			{ DAHDI_TONE_CALLWAIT, "400+16/500,0/8000" },
			{ DAHDI_TONE_DIALRECALL, "!400/200,!0/200,!400/200,!0/200,!400/200,!0/200,400" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,0" },
			{ DAHDI_TONE_STUTTER, "!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,400" },
		},
	  .dtmf_high_level = -7,
	  .dtmf_low_level = -7,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 8,
	  .country = "no",
	  .description = "Norway",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "425/200,0/600,425/200,0/10000" },
			{ DAHDI_TONE_DIALRECALL, "470/400,425/400" },
			{ DAHDI_TONE_RECORDTONE, "1400/400,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,0" },
			{ DAHDI_TONE_STUTTER, "470/400,425/400" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 9,
	  .country =  "at",
	  .description = "Austria",
	  .ringcadence = { 1000, 5000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "420" },
			{ DAHDI_TONE_BUSY, "420/400,0/400" },
			{ DAHDI_TONE_RINGTONE, "420/1000,0/5000" },
			{ DAHDI_TONE_CONGESTION, "420/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "420/40,0/1960" },
			{ DAHDI_TONE_DIALRECALL, "420" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/80,0/14920" },
			{ DAHDI_TONE_INFO, "950/330,1450/330,1850/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "380+420" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 10,
	  .country =  "nz",
	  .description = "New Zealand",
	  .ringcadence = { 400, 200, 400, 2000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "400" },
			{ DAHDI_TONE_BUSY, "400/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "400+450/400,0/200,400+450/400,0/2000" },
			{ DAHDI_TONE_CONGESTION, "400/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "400/250,0/250,400/250,0/3250" },
			{ DAHDI_TONE_DIALRECALL, "!400/100!0/100,!400/100,!0/100,!400/100,!0/100,400" },
			{ DAHDI_TONE_RECORDTONE, "1400/425,0/15000" },
			{ DAHDI_TONE_INFO, "400/750,0/100,400/750,0/100,400/750,0/100,400/750,0/400" },
			{ DAHDI_TONE_STUTTER, "!400/100!0/100,!400/100,!0/100,!400/100,!0/100,!400/100!0/100,!400/100,!0/100,!400/100,!0/100,400" },
		},
	  .dtmf_high_level = -11,
	  .dtmf_low_level = -9,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 11,
	  .country = "it",
	  .description = "Italy",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425/200,0/200,425/600,0/1000" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "425/400,0/100,425/250,0/100,425/150,0/14000" },
			{ DAHDI_TONE_DIALRECALL, "470/400,425/400" },
			{ DAHDI_TONE_RECORDTONE, "1400/400,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,0" },
			{ DAHDI_TONE_STUTTER, "470/400,425/400" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 12,
	  .country = "us-old",
	  .description = "United States Circa 1950 / North America",
	  .ringcadence = { 2000, 4000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "600*120" },
			{ DAHDI_TONE_BUSY, "500*100/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "420*40/2000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "500*100/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "440/300,0/10000" },
			{ DAHDI_TONE_DIALRECALL, "!600*120/100,!0/100,!600*120/100,!0/100,!600*120/100,!0/100,600*120" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,0" },
			{ DAHDI_TONE_STUTTER, "!600*120/100,!0/100,!600*120/100,!0/100,!600*120/100,!0/100,!600*120/100,!0/100,!600*120/100,!0/100,!600*120/100,!0/100,600*120" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 13,
	  .country = "gr",
	  .description = "Greece",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425/200,0/300,425/700,0/800" },
			{ DAHDI_TONE_BUSY, "425/300,0/300" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "425/150,0/150,425/150,0/8000" },
			{ DAHDI_TONE_DIALRECALL, "425/650,0/25" },
			{ DAHDI_TONE_RECORDTONE, "1400/400,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,0" },
			{ DAHDI_TONE_STUTTER, "425/650,0/25" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 14,
	  .country = "tw",
	  .description = "Taiwan",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "350+440" },
			{ DAHDI_TONE_BUSY, "480+620/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "440+480/1000,0/2000" },
			{ DAHDI_TONE_CONGESTION, "480+620/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "350+440/250,0/250,350+440/250,0/3250" },
			{ DAHDI_TONE_DIALRECALL, "300/1500,0/500" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,0" },
			{ DAHDI_TONE_STUTTER, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
		},
	  .dtmf_high_level = -11,
	  .dtmf_low_level = -9,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 15,
	  .country = "cl",
	  .description = "Chile",
	  .ringcadence = { 1000, 3000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "400" },
			{ DAHDI_TONE_BUSY, "400/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "400/1000,0/3000" },
			{ DAHDI_TONE_CONGESTION, "400/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "400/250,0/8750" },
			{ DAHDI_TONE_DIALRECALL, "!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,400" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/333,!1400/333,!1800/333,0" },
			{ DAHDI_TONE_STUTTER, "!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,!400/100,!0/100,400" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 16,
	  .country = "se",
	  .description = "Sweden",
	  .ringcadence = { 1000, 5000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/250,0/250" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/5000" },
			{ DAHDI_TONE_CONGESTION, "425/250,0/750" },
			{ DAHDI_TONE_CALLWAIT, "425/200,0/500,425/200,0/9100" },
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/332,!0/24,!1400/332,!0/24,!1800/332,!0/2024,"
			  "!950/332,!0/24,!1400/332,!0/24,!1800/332,!0/2024,"
			  "!950/332,!0/24,!1400/332,!0/24,!1800/332,!0/2024,"
			  "!950/332,!0/24,!1400/332,!0/24,!1800/332,!0/2024,"
			  "!950/332,!0/24,!1400/332,!0/24,!1800/332,0" },
			/*{ DAHDI_TONE_STUTTER, "425/320,0/20" },              Real swedish standard, not used for now */
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 17,
	  .country = "be",
	  .description = "Belgium",
	  .ringcadence = { 1000, 3000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/3000" },
			{ DAHDI_TONE_CONGESTION, "425/167,0/167" },
			{ DAHDI_TONE_CALLWAIT, "1400/175,0/175,1400/175,0/3500" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "900/330,1400/330,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "425/1000,0/250" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 18,
	  .country = "sg",
	  .description = "Singapore",
	  .ringcadence = { 400, 200, 400, 2000 },
	  .tones = {
			/* Reference: http://www.ida.gov.sg/idaweb/doc/download/I397/ida_ts_pstn1_i4r2.pdf */
			{ DAHDI_TONE_DIALTONE,   "425" },
			{ DAHDI_TONE_BUSY,       "425/750,0/750" },
			{ DAHDI_TONE_RINGTONE,   "425*24/400,0/200,425*24/400,0/2000" },
			{ DAHDI_TONE_CONGESTION, "425/250,0/250" },
			{ DAHDI_TONE_CALLWAIT,   "425*24/300,0/200,425*24/300,0/3200" },
			/* DIALRECALL - not specified - use repeating Holding Tone A,B*/
			{ DAHDI_TONE_DIALRECALL, "425*24/500,0/500,425/500,0/2500" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO,       "950/330,1400/330,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER,    "!425/200,!0/200,!425/600,!0/200,!425/200,!0/200,!425/600,!0/200,!425/200,!0/200,!425/600,!0/200,!425/200,!0/200,!425/600,!0/200,425" },
		},
	  .dtmf_high_level = -11,
	  .dtmf_low_level = -9,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 19,
	  .country = "il",
	  .description = "Israel",
	  .ringcadence = { 1000, 3000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "414" },
			{ DAHDI_TONE_BUSY, "414/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "414/1000,0/3000" },
			{ DAHDI_TONE_CONGESTION, "414/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "414/100,0/100,414/100,0/100,414/600,0/3000" },
			{ DAHDI_TONE_DIALRECALL, "!414/100,!0/100,!414/100,!0/100,!414/100,!0/100,414" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "1000/330,1400/330,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "!414/160,!0/160,!414/160,!0/160,!414/160,!0/160,!414/160,!0/160,!414/160,!0/160,!414/160,!0/160,!414/160,!0/160,!414/160,!0/160,!414/160,!0/160,!414/160,!0/160,414" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 20,
	  .country = "br",
	  .description = "Brazil",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/250,0/250" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/250,0/250,425/750,0/250" },
			{ DAHDI_TONE_CALLWAIT, "425/50,0/1000" },
			{ DAHDI_TONE_DIALRECALL, "350+440" },
			{ DAHDI_TONE_RECORDTONE, "425/250,0/250" },
			{ DAHDI_TONE_INFO, "950/330,1400/330,1800/330" },
			{ DAHDI_TONE_STUTTER, "350+440" } },
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -12,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 21,
	  .country = "hu",
	  .description = "Hungary",
	  .ringcadence = { 1250, 3750 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/300,0/300" },
			{ DAHDI_TONE_RINGTONE, "425/1250,0/3750" },
			{ DAHDI_TONE_CONGESTION, "425/300,0/300" },
			{ DAHDI_TONE_CALLWAIT, "425/40,0/1960" },
			{ DAHDI_TONE_DIALRECALL, "425+450" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/400,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,0" },
			{ DAHDI_TONE_STUTTER, "350+375+400" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 22,
	  .country = "lt",
	  .description = "Lithuania",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/350,0/350" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "425/150,0/150,425/150,0/4000" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,0" },
			/* STUTTER not specified */
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 23,
	  .country = "pl",
	  .description = "Poland",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/500,0/500" },
			{ DAHDI_TONE_CALLWAIT, "425/150,0/150,425/150,0/4000" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,0" },
			/* STUTTER not specified */
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 24,
	  .country = "za",
	  .description = "South Africa",
	  .ringcadence = { 400, 200, 400, 2000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "400*33" },
			{ DAHDI_TONE_BUSY, "400/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "400*33/400,0/200,400*33/400,0/2000" },
			{ DAHDI_TONE_CONGESTION, "400/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "400*33/250,0/250,400*33/250,0/250,400*33/250,0/250,400*33/250,0/250" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "350+440" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,!950/330,!1400/330,!1800/330,!0/1000,0" },
			/* STUTTER not specified */
			{ DAHDI_TONE_STUTTER, "!400*33/100,!0/100,!400*33/100,!0/100,!400*33/100,!0/100,!400*33/100,!0/100,!400*33/100,!0/100,!400*33/100,!0/100,400*33" },
		},
	  .dtmf_high_level = -11,
	  .dtmf_low_level = -13,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 25,
	  .country = "pt",
	  .description = "Portugal",
	  .ringcadence = { 1000, 5000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/5000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "425/200,425/200,425/200,0/5000" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "425/1000,0/200" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "950/330,1400/330,1800/330,0/1000" },
			/* STUTTER not specified */
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 26,
	  .country = "ee",
	  .description = "Estonia",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/300,0/300" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "950/650,0/325,950/325,0/30,1400/1300,0/2600" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "425/650,0/25" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "950/0,0/325,950/325,0/30,1400/1300,0/2600" },
			/* STUTTER not specified */
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 27,
	  .country = "mx",
	  .description = "Mexico",
	  .ringcadence = { 2000, 4000 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/250,0/250" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "425/200,0/600,425/200,0/10000" },
			{ DAHDI_TONE_DIALRECALL, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "950/330,0/30,1400/330,0/30,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
		},
	  .dtmf_high_level = -8,
	  .dtmf_low_level = -6,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 28,
	  .country = "in",
	  .description = "India",
	  .ringcadence = { 400, 200, 400, 2000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "400*25" },
			{ DAHDI_TONE_BUSY, "400/750,0/750" },
			{ DAHDI_TONE_RINGTONE, "400*25/400,0/200,400*25/400,0/2000" },
			{ DAHDI_TONE_CONGESTION, "400/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "400/200,0/100,400/200,0/7500" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			/* INFO - not specified */
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,0/1000" },
			/* STUTTER - not specified */
			{ DAHDI_TONE_STUTTER, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 29,
	  .country = "de",
	  .description = "Germany",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/480,0/480" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/240,0/240" },
			{ DAHDI_TONE_CALLWAIT, "!425/200,!0/200,!425/200,!0/5000,!425/200,!0/200,!425/200,!0/5000,!425/200,!0/200,!425/200,!0/5000,!425/200,!0/200,!425/200,!0/5000,!425/200,!0/200,!425/200,0" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/80,0/15000" },
			{ DAHDI_TONE_INFO, "950/330,1400/330,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "425+400" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 30,
	  .country = "ch",
	  .description = "Switzerland",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "425/200,0/200,425/200,0/4000" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/80,0/15000" },
			{ DAHDI_TONE_INFO, "950/330,1400/330,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "425+340/1100,0/1100" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 31,
	  .country = "dk",
	  .description = "Denmark",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/200" },
			{ DAHDI_TONE_CALLWAIT, "!425/200,!0/600,!425/200,!0/3000,!425/200,!0/200,!425/200,0" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/80,0/15000" },
			{ DAHDI_TONE_INFO, "950/330,1400/330,1800/330,0/1000" },
			/* STUTTER - not specified */
			{ DAHDI_TONE_STUTTER, "425/450,0/50" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 32,
	  .country = "cz",
	  .description = "Czech Republic",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425/330,0/330,425/660,0/660" },
			{ DAHDI_TONE_BUSY, "425/330,0/330" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/165,0/165" },
			{ DAHDI_TONE_CALLWAIT, "425/330,0/9000" },
			/* DIALRECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425/330,0/330,425/660,0/660" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/14000" },
			{ DAHDI_TONE_INFO, "950/330,0/30,1400/330,0/30,1800/330,0/1000" },
			/* STUTTER - not specified */
			{ DAHDI_TONE_STUTTER, "425/450,0/50" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 33,
	  .country = "cn",
	  .description = "China",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "450" },
			{ DAHDI_TONE_BUSY, "450/350,0/350" },
			{ DAHDI_TONE_RINGTONE, "450/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "450/700,0/700" },
			{ DAHDI_TONE_CALLWAIT, "450/400,0/4000" },
			{ DAHDI_TONE_DIALRECALL, "450" },
			{ DAHDI_TONE_RECORDTONE, "950/400,0/10000" },
			{ DAHDI_TONE_INFO, "450/100,0/100,450/100,0/100,450/100,0/100,450/400,0/400" },
			/* STUTTER - not specified */
			{ DAHDI_TONE_STUTTER, "450+425" },
		},
	  .dtmf_high_level = -11,
	  .dtmf_low_level = -9,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 34,
	  .country = "ar",
	  .description = "Argentina",
	  .ringcadence = { 1000, 4500 },
	  .tones = {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/300,0/300" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4500" },
			{ DAHDI_TONE_CONGESTION, "425/200,0/300" },
			{ DAHDI_TONE_CALLWAIT, "425/200,0/9000" },
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425/330,0/330,425/660,0/660" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/14000" },
			{ DAHDI_TONE_INFO, "425/100,0/100" },
			{ DAHDI_TONE_STUTTER, "425/450,0/50" },
		},
	  .dtmf_high_level = -11,
	  .dtmf_low_level = -9,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 35,
	  .country = "my",
	  .description = "Malaysia",
	  .ringcadence = { 400, 200, 400, 2000 },
	  .tones =   {
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/400,0/200,425/400,0/2000" },
			{ DAHDI_TONE_CONGESTION, "425/500,0/500" },
			{ DAHDI_TONE_CALLWAIT, "425/100,0/4000" },
			{ DAHDI_TONE_DIALRECALL, "350+440" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/60000" },
			{ DAHDI_TONE_INFO, "950/330,0/15,1400/330,0/15,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "450+425" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{ .zone = 36,
	  .country = "th",
	  .description = "Thailand",
	  .ringcadence = { 1000, 4000 },
	  .tones =        {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE,   "400*50" },
			{ DAHDI_TONE_BUSY,       "400/500,0/500" },
			{ DAHDI_TONE_RINGTONE,   "400/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "400/300,0/300" },
			{ DAHDI_TONE_CALLWAIT,   "1000/400,10000/400,1000/400" },
			/* DIALRECALL - not specified - use special dial tone instead. */
			{ DAHDI_TONE_DIALRECALL, "400*50/400,0/100,400*50/400,0/100" },
			/* RECORDTONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			/* INFO - specified as an announcement - use tones instead. */
			{ DAHDI_TONE_INFO,       "950/330,1400/330,1800/330" },
			/* STUTTER - not specified */
			{ DAHDI_TONE_STUTTER,    "!400/200,!0/200,!400/600,!0/200,!400/200,!0/200,!400/600,!0/200,!400/200,!0/200,!400/600,!0/200,!400/200,!0/200,!400/600,!0/200,400" },
		},
	  .dtmf_high_level = -11,
	  .dtmf_low_level = -9,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
	},
	{ .zone = 37,
	  .country = "bg",
	  .description = "Bulgaria",
	  .ringcadence = { 1000, 4000 },
	  .tones =        {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE,   "425" },
			{ DAHDI_TONE_BUSY,       "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE,   "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/250,0/250" },
			{ DAHDI_TONE_CALLWAIT,   "425/150,0/150,425/150,0/4000" },
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
			{ DAHDI_TONE_RECORDTONE, "1400/425,0/15000" },
			{ DAHDI_TONE_INFO,       "950/330,1400/330,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER,    "425/1500,0/100" },
		},
	  .dtmf_high_level = -9,
	  .dtmf_low_level = -11,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
        { .zone = 38,
	  .country = "ve",
	  .description = "Venezuela",
	  .ringcadence = { 1000, 4000 },
	  .tones =        {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "400+450/300,0/6000" },
			{ DAHDI_TONE_DIALRECALL, "425" },
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1440/330,!1800/330,0/1000" },
			/* STUTTER - not specified */
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
		},
	  .dtmf_high_level = -7,
	  .dtmf_low_level = -9,
	  .mfr1_level = -7,
	  .mfr2_level = -8,
        },
        { .zone = 39,
	  .country = "ph",
	  .description = "Philippines",
	  .ringcadence = { 1000, 4000 },
	  .tones =        {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "480+620/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425+480/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "480+620/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "440/300,0/10000" },
			/* DIAL RECALL - not specified */
			{ DAHDI_TONE_DIALRECALL, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
			/* RECORD TONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			/* INFO TONE - not specified */
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,0" },
			/* STUTTER TONE - not specified */
			{ DAHDI_TONE_STUTTER, "!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,!350+440/100,!0/100,350+440" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
        },
	{ .zone = 40,
	  .country = "ru",
	  .description = "Russian Federation",
	  .ringcadence = { 1000, 4000 },
	  .tones = {
			/* References:
			   http://www.minsvyaz.ru/site.shtml?id=1806
			   http://www.aboutphone.info/lib/gost/45-223-2001.html */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/350,0/350" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/175,0/175" },
			{ DAHDI_TONE_CALLWAIT, "425/200,0/5000" },
			{ DAHDI_TONE_RECORDTONE, "1400/400,0/15000" },
			{ DAHDI_TONE_INFO, "950/330,1440/330,1800/330,0/1000" },
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
		},
	  .dtmf_high_level = -10,
	  .dtmf_low_level = -10,
	  .mfr1_level = -10,
	  .mfr2_level = -8,
	},
	{
		.zone = 41,
		.country = "tr",
		.description = "Turkey",
		.ringcadence = { 2000, 4000 },
		.tones = {
			{ DAHDI_TONE_DIALTONE,   "450" },
			{ DAHDI_TONE_BUSY,       "450/500,0/500" },
			{ DAHDI_TONE_RINGTONE,   "450/2000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "!450/200,!0/200,!450/200,!0/200,!450/200,!0/200,450/600,0/200" },
			{ DAHDI_TONE_CALLWAIT,   "450/200,0/600,450/200,0/800" },
			/* This should actually be 950+1400+1800, but we only support 2 tones at a time */
			{ DAHDI_TONE_INFO,       "!950+1400/300,!0/1000,!950+1400/300,!0/1000,!950+1400/1000,0" },
			{ DAHDI_TONE_STUTTER,    "!450/100,!0/100,!450/100,!0/100,!450/100,!0/100,!450/100,!0/100,!450/100,!0/100,!450/100,!0/100,450" },
		},
		.dtmf_high_level = -10,
		.dtmf_low_level = -10,
		.mfr1_level = -10,
		.mfr2_level = -8,
	},
	{
		.zone = 42,
		.country = "pa",
		.description = "Panama",
		.ringcadence = { 2000, 4000 },
		.tones = {
			/* Reference: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/320,0/320" },
			{ DAHDI_TONE_RINGTONE, "425/1200,0/4650" },
			{ DAHDI_TONE_CONGESTION, "425/320,0/320" },
			{ DAHDI_TONE_CALLWAIT, "425/180,0/180,425/180" },
			/* RECALL DIAL TONE - not specified */
			{ DAHDI_TONE_DIALRECALL, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
			/* RECORD TONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/500,0/15000" },
			{ DAHDI_TONE_INFO, "!950/330,!1400/330,!1800/330,0" },
			/* STUTTER TONE - not specified */
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
		},
		.dtmf_high_level = -9,
		.dtmf_low_level = -11,
		.mfr1_level = -7,
		.mfr2_level = -8,
	},
	{
		.zone = 43,
		.country = "mo",
		.description = "Macao,China",
		.ringcadence = { 1000, 4000 },
		.tones = {
			/* References: http://www.itu.int/ITU-T/inr/forms/files/tones-0203.pdf */
			{ DAHDI_TONE_DIALTONE, "425" },
			{ DAHDI_TONE_BUSY, "425/500,0/500" },
			{ DAHDI_TONE_RINGTONE, "425/1000,0/4000" },
			{ DAHDI_TONE_CONGESTION, "425/250,0/250" },
			{ DAHDI_TONE_CALLWAIT, "425/200,0/600" },
			/* RECORD TONE - not specified */
			{ DAHDI_TONE_RECORDTONE, "1400/400,0/15000" },
			{ DAHDI_TONE_INFO, "950/333,1400/333,1800/333,0/1000" },
			/* STUTTER TONE - not specified */
			{ DAHDI_TONE_STUTTER, "!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,!425/100,!0/100,425" },
	},
		.dtmf_high_level = -10,
		.dtmf_low_level = -10,
		.mfr1_level = -10,
		.mfr2_level = -8,
	},
	{ .zone = -1 }
};