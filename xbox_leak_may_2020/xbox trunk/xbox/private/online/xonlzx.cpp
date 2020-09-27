/*
 * decapi.c
 *
 * API entry points.
 */

#include "xonp.h"
#include "xonver.h"

const byte NEAR dec_extra_bits[] =
{
	0,0,0,0,1,1,2,2,
	3,3,4,4,5,5,6,6,
	7,7,8,8,9,9,10,10,
	11,11,12,12,13,13,14,14,
	15,15,16,16,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,
	17,17,17
};

/*
 * first (base) position covered by each slot
 * 2 subtracted for optimisation purposes (see decverb.c/decalign.c comments)
 */
const long NEAR MP_POS_minus2[sizeof(dec_extra_bits)] =
{
	0-2,        1-2,        2-2,        3-2,        4-2,        6-2,        8-2,        12-2,
	16-2,       24-2,       32-2,       48-2,       64-2,       96-2,       128-2,      192-2,
	256-2,      384-2,      512-2,      768-2,      1024-2,     1536-2,     2048-2,     3072-2,
	4096-2,     6144-2,     8192-2,     12288-2,    16384-2,    24576-2,    32768-2,    49152-2,
	65536-2,    98304-2,    131072-2,   196608-2,   262144-2,   393216-2,   524288-2,   655360-2,
	786432-2,   917504-2,   1048576-2,  1179648-2,  1310720-2,  1441792-2,  1572864-2,  1703936-2,
	1835008-2,  1966080-2,  2097152-2,  2228224-2,  2359296-2,  2490368-2,  2621440-2,  2752512-2,
	2883584-2,  3014656-2,  3145728-2,  3276800-2,  3407872-2,  3538944-2,  3670016-2,  3801088-2,
	3932160-2,  4063232-2,  4194304-2,  4325376-2,  4456448-2,  4587520-2,  4718592-2,  4849664-2,
	4980736-2,  5111808-2,  5242880-2,  5373952-2,  5505024-2,  5636096-2,  5767168-2,  5898240-2,
	6029312-2,  6160384-2,  6291456-2,  6422528-2,  6553600-2,  6684672-2,  6815744-2,  6946816-2,
	7077888-2,  7208960-2,  7340032-2,  7471104-2,  7602176-2,  7733248-2,  7864320-2,  7995392-2,
	8126464-2,  8257536-2,  8388608-2,  8519680-2,  8650752-2,  8781824-2,  8912896-2,  9043968-2,
	9175040-2,  9306112-2,  9437184-2,  9568256-2,  9699328-2,  9830400-2,  9961472-2,  10092544-2,
	10223616-2, 10354688-2, 10485760-2, 10616832-2, 10747904-2, 10878976-2, 11010048-2, 11141120-2,
	11272192-2, 11403264-2, 11534336-2, 11665408-2, 11796480-2, 11927552-2, 12058624-2, 12189696-2,
	12320768-2, 12451840-2, 12582912-2, 12713984-2, 12845056-2, 12976128-2, 13107200-2, 13238272-2,
	13369344-2, 13500416-2, 13631488-2, 13762560-2, 13893632-2, 14024704-2, 14155776-2, 14286848-2,
	14417920-2, 14548992-2, 14680064-2, 14811136-2, 14942208-2, 15073280-2, 15204352-2, 15335424-2,
	15466496-2, 15597568-2, 15728640-2, 15859712-2, 15990784-2, 16121856-2, 16252928-2, 16384000-2,
	16515072-2, 16646144-2, 16777216-2, 16908288-2, 17039360-2, 17170432-2, 17301504-2, 17432576-2,
	17563648-2, 17694720-2, 17825792-2, 17956864-2, 18087936-2, 18219008-2, 18350080-2, 18481152-2,
	18612224-2, 18743296-2, 18874368-2, 19005440-2, 19136512-2, 19267584-2, 19398656-2, 19529728-2,
	19660800-2, 19791872-2, 19922944-2, 20054016-2, 20185088-2, 20316160-2, 20447232-2, 20578304-2,
	20709376-2, 20840448-2, 20971520-2, 21102592-2, 21233664-2, 21364736-2, 21495808-2, 21626880-2,
	21757952-2, 21889024-2, 22020096-2, 22151168-2, 22282240-2, 22413312-2, 22544384-2, 22675456-2,
	22806528-2, 22937600-2, 23068672-2, 23199744-2, 23330816-2, 23461888-2, 23592960-2, 23724032-2,
	23855104-2, 23986176-2, 24117248-2, 24248320-2, 24379392-2, 24510464-2, 24641536-2, 24772608-2,
	24903680-2, 25034752-2, 25165824-2, 25296896-2, 25427968-2, 25559040-2, 25690112-2, 25821184-2,
	25952256-2, 26083328-2, 26214400-2, 26345472-2, 26476544-2, 26607616-2, 26738688-2, 26869760-2,
	27000832-2, 27131904-2, 27262976-2, 27394048-2, 27525120-2, 27656192-2, 27787264-2, 27918336-2,
	28049408-2, 28180480-2, 28311552-2, 28442624-2, 28573696-2, 28704768-2, 28835840-2, 28966912-2,
	29097984-2, 29229056-2, 29360128-2, 29491200-2, 29622272-2, 29753344-2, 29884416-2, 30015488-2,
	30146560-2, 30277632-2, 30408704-2, 30539776-2, 30670848-2, 30801920-2, 30932992-2, 31064064-2,
	31195136-2, 31326208-2, 31457280-2, 31588352-2, 31719424-2, 31850496-2, 31981568-2, 32112640-2,
	32243712-2, 32374784-2, 32505856-2, 32636928-2, 32768000-2, 32899072-2, 33030144-2, 33161216-2,
	33292288-2, 33423360-2, 33554432-2
};

/*
 * Set/reset decoder trees to initial state
 */
void NEAR reset_decoder_trees(t_decoder_context *context)
{
	memset(context->dec_main_tree_len, 0, MAIN_TREE_ELEMENTS);
	memset(context->dec_main_tree_prev_len, 0, MAIN_TREE_ELEMENTS);

	memset(context->dec_secondary_length_tree_len, 0, NUM_SECONDARY_LENGTHS);
	memset(context->dec_secondary_length_tree_prev_len, 0, NUM_SECONDARY_LENGTHS);
}


/*
 * Miscellaneous state initialisations
 */
void NEAR decoder_misc_init(t_decoder_context *context)
{
	context->dec_last_matchpos_offset[0] = 1;
	context->dec_last_matchpos_offset[1] = 1;
	context->dec_last_matchpos_offset[2] = 1;

	context->dec_bufpos = 0;
    context->dec_position_at_start = 0;

	context->dec_decoder_state	= DEC_STATE_START_NEW_BLOCK;
	context->dec_block_size		= 0;

    /* so that initialise_decoder_bitbuf() will succeed */
    context->dec_block_type     = BLOCKTYPE_INVALID;

	context->dec_first_time_this_group	= true;
	context->dec_current_file_size		= 0;

    context->dec_error_condition = false;
}


void CXo::LzxResetDecoder(PXONLINE_LZXDECODER_CONTEXT pContext)
{
	reset_decoder_trees(pContext);
	decoder_misc_init(pContext);
	init_decoder_translation(pContext);
    pContext->dec_num_cfdata_frames = 0;
}

bool CXo::LzxDecodeInit(byte * pbWindowBuffer, ulong ulWindowSize, PXONLINE_LZXDECODER_CONTEXT pContext)
{
	ulong	pos_start;

//	Assert(pbWindowBuffer != NULL);
//	Assert(pContext != NULL);

	// Decompression window size must be a power of two
//  Assert((dwWindowSize & (dwWindowSize - 1)) == 0);
		
	pContext->dec_window_size = ulWindowSize;
	pContext->dec_mem_window = pbWindowBuffer;
	pContext->dec_window_mask = pContext->dec_window_size - 1;

	// Extra long matches not supported by default
	pContext->dec_extra_long_matches = FALSE;

	// Figure out how many slots given the window size
	pContext->dec_num_position_slots = 4;
	pos_start = 4;

	while (1)
	{
        pos_start += 1L << dec_extra_bits[pContext->dec_num_position_slots];

		pContext->dec_num_position_slots++;

		if (pos_start >= pContext->dec_window_size)
			break;
	}

	// Initialize the decoder context
	LzxResetDecoder(pContext);

	return(true);
}

void CXo::LzxEnableExtraLongMatches(PXONLINE_LZXDECODER_CONTEXT pContext)
{
	pContext->dec_extra_long_matches = TRUE;
}

bool CXo::LzxDecode(
			PXONLINE_LZXDECODER_CONTEXT	pContext,
			ulong						cbDecodedSize,
			byte						*pbInput,
			ulong						cbInput,
			byte						*pbOutput,
			ulong						*pcbBytesDecoded
			)
{
	bool	fResult = true;
	long	lDecoded;

//	Assert(pContext != NULL);
//	Assert(pbInput != NULL);
//	Assert(cbInput != 0);
//	Assert(pbOutput != NULL);
//	Assert(cbDecodedSize >= cbInput);

   	if (pcbBytesDecoded)
		*pcbBytesDecoded = 0;

    pContext->dec_input_curpos   = pbInput;
    pContext->dec_end_input_pos  = (pbInput + cbInput + 4);

    pContext->dec_output_buffer  = pbOutput;

	init_decoder_input(pContext);

	// Call the decode function
	lDecoded = decode_data(pContext, cbDecodedSize);
    if (lDecoded < 0)
    {
    	// Failure
    	fResult = false;
    }
    else
    {
	    // Update next starting position
        pContext->dec_position_at_start += lDecoded;

    	if (pcbBytesDecoded)
	        *pcbBytesDecoded = lDecoded;
	}

    pContext->dec_num_cfdata_frames++;

    return(fResult);
}

bool CXo::LzxPopulateDictionary(
			PXONLINE_LZXDECODER_CONTEXT pContext, 
			byte *pbData, 
			ulong cbData)
{
    if (cbData > pContext->dec_window_size)
        return(false);

    memcpy(&(pContext->dec_mem_window[pContext->dec_window_size - cbData]), pbData, cbData);

    return(true);
}

