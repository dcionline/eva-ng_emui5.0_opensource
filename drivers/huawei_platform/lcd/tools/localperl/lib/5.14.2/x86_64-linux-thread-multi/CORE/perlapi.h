/* -*- buffer-read-only: t -*-
 *
 *    perlapi.h
 *
 *    Copyright (C) 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001,
 *    2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 * This file is built by regen/embed.pl from data in embed.fnc,
 * regen/embed.pl, regen/opcodes, intrpvar.h and perlvars.h.
 * Any changes made here will be lost!
 *
 * Edit those files and run 'make regen_headers' to effect changes.
 */

/* declare accessor functions for Perl variables */
#ifndef __perlapi_h__
#define __perlapi_h__

#if defined (MULTIPLICITY) && defined (PERL_GLOBAL_STRUCT)

START_EXTERN_C

#undef PERLVAR
#undef PERLVARA
#undef PERLVARI
#undef PERLVARIC
#undef PERLVARISC
#define PERLVAR(v,t)	EXTERN_C t* Perl_##v##_ptr(pTHX);
#define PERLVARA(v,n,t)	typedef t PL_##v##_t[n];			\
			EXTERN_C PL_##v##_t* Perl_##v##_ptr(pTHX);
#define PERLVARI(v,t,i)	PERLVAR(v,t)
#define PERLVARIC(v,t,i) PERLVAR(v, const t)
#define PERLVARISC(v,i)	typedef const char PL_##v##_t[sizeof(i)];	\
			EXTERN_C PL_##v##_t* Perl_##v##_ptr(pTHX);

#include "perlvars.h"

#undef PERLVAR
#undef PERLVARA
#undef PERLVARI
#undef PERLVARIC
#undef PERLVARISC

END_EXTERN_C

#if defined(PERL_CORE)

/* accessor functions for Perl "global" variables */

/* these need to be mentioned here, or most linkers won't put them in
   the perl executable */

#ifndef PERL_NO_FORCE_LINK

START_EXTERN_C

#ifndef DOINIT
EXTCONST void * const PL_force_link_funcs[];
#else
EXTCONST void * const PL_force_link_funcs[] = {
#undef PERLVAR
#undef PERLVARA
#undef PERLVARI
#undef PERLVARIC
#define PERLVAR(v,t)	(void*)Perl_##v##_ptr,
#define PERLVARA(v,n,t)	PERLVAR(v,t)
#define PERLVARI(v,t,i)	PERLVAR(v,t)
#define PERLVARIC(v,t,i) PERLVAR(v,t)
#define PERLVARISC(v,i) PERLVAR(v,char)

/* In Tru64 (__DEC && __osf__) the cc option -std1 causes that one
 * cannot cast between void pointers and function pointers without
 * info level warnings.  The PL_force_link_funcs[] would cause a few
 * hundred of those warnings.  In code one can circumnavigate this by using
 * unions that overlay the different pointers, but in declarations one
 * cannot use this trick.  Therefore we just disable the warning here
 * for the duration of the PL_force_link_funcs[] declaration. */

#if defined(__DECC) && defined(__osf__)
#pragma message save
#pragma message disable (nonstandcast)
#endif

#include "perlvars.h"

#if defined(__DECC) && defined(__osf__)
#pragma message restore
#endif

#undef PERLVAR
#undef PERLVARA
#undef PERLVARI
#undef PERLVARIC
#undef PERLVARISC
};
#endif	/* DOINIT */

END_EXTERN_C

#endif	/* PERL_NO_FORCE_LINK */

#else	/* !PERL_CORE */

#undef  PL_No
#define PL_No			(*Perl_GNo_ptr(NULL))
#undef  PL_Yes
#define PL_Yes			(*Perl_GYes_ptr(NULL))
#undef  PL_appctx
#define PL_appctx		(*Perl_Gappctx_ptr(NULL))
#undef  PL_charclass
#define PL_charclass		(*Perl_Gcharclass_ptr(NULL))
#undef  PL_check
#define PL_check		(*Perl_Gcheck_ptr(NULL))
#undef  PL_csighandlerp
#define PL_csighandlerp		(*Perl_Gcsighandlerp_ptr(NULL))
#undef  PL_curinterp
#define PL_curinterp		(*Perl_Gcurinterp_ptr(NULL))
#undef  PL_do_undump
#define PL_do_undump		(*Perl_Gdo_undump_ptr(NULL))
#undef  PL_dollarzero_mutex
#define PL_dollarzero_mutex	(*Perl_Gdollarzero_mutex_ptr(NULL))
#undef  PL_fold_locale
#define PL_fold_locale		(*Perl_Gfold_locale_ptr(NULL))
#undef  PL_global_struct_size
#define PL_global_struct_size	(*Perl_Gglobal_struct_size_ptr(NULL))
#undef  PL_hexdigit
#define PL_hexdigit		(*Perl_Ghexdigit_ptr(NULL))
#undef  PL_hints_mutex
#define PL_hints_mutex		(*Perl_Ghints_mutex_ptr(NULL))
#undef  PL_interp_size
#define PL_interp_size		(*Perl_Ginterp_size_ptr(NULL))
#undef  PL_interp_size_5_10_0
#define PL_interp_size_5_10_0	(*Perl_Ginterp_size_5_10_0_ptr(NULL))
#undef  PL_keyword_plugin
#define PL_keyword_plugin	(*Perl_Gkeyword_plugin_ptr(NULL))
#undef  PL_malloc_mutex
#define PL_malloc_mutex		(*Perl_Gmalloc_mutex_ptr(NULL))
#undef  PL_mmap_page_size
#define PL_mmap_page_size	(*Perl_Gmmap_page_size_ptr(NULL))
#undef  PL_my_ctx_mutex
#define PL_my_ctx_mutex		(*Perl_Gmy_ctx_mutex_ptr(NULL))
#undef  PL_my_cxt_index
#define PL_my_cxt_index		(*Perl_Gmy_cxt_index_ptr(NULL))
#undef  PL_op_mutex
#define PL_op_mutex		(*Perl_Gop_mutex_ptr(NULL))
#undef  PL_op_seq
#define PL_op_seq		(*Perl_Gop_seq_ptr(NULL))
#undef  PL_op_sequence
#define PL_op_sequence		(*Perl_Gop_sequence_ptr(NULL))
#undef  PL_patleave
#define PL_patleave		(*Perl_Gpatleave_ptr(NULL))
#undef  PL_perlio_debug_fd
#define PL_perlio_debug_fd	(*Perl_Gperlio_debug_fd_ptr(NULL))
#undef  PL_perlio_fd_refcnt
#define PL_perlio_fd_refcnt	(*Perl_Gperlio_fd_refcnt_ptr(NULL))
#undef  PL_perlio_fd_refcnt_size
#define PL_perlio_fd_refcnt_size	(*Perl_Gperlio_fd_refcnt_size_ptr(NULL))
#undef  PL_perlio_mutex
#define PL_perlio_mutex		(*Perl_Gperlio_mutex_ptr(NULL))
#undef  PL_ppaddr
#define PL_ppaddr		(*Perl_Gppaddr_ptr(NULL))
#undef  PL_revision
#define PL_revision		(*Perl_Grevision_ptr(NULL))
#undef  PL_runops_dbg
#define PL_runops_dbg		(*Perl_Grunops_dbg_ptr(NULL))
#undef  PL_runops_std
#define PL_runops_std		(*Perl_Grunops_std_ptr(NULL))
#undef  PL_sh_path
#define PL_sh_path		(*Perl_Gsh_path_ptr(NULL))
#undef  PL_sig_defaulting
#define PL_sig_defaulting	(*Perl_Gsig_defaulting_ptr(NULL))
#undef  PL_sig_handlers_initted
#define PL_sig_handlers_initted	(*Perl_Gsig_handlers_initted_ptr(NULL))
#undef  PL_sig_ignoring
#define PL_sig_ignoring		(*Perl_Gsig_ignoring_ptr(NULL))
#undef  PL_sig_trapped
#define PL_sig_trapped		(*Perl_Gsig_trapped_ptr(NULL))
#undef  PL_sigfpe_saved
#define PL_sigfpe_saved		(*Perl_Gsigfpe_saved_ptr(NULL))
#undef  PL_subversion
#define PL_subversion		(*Perl_Gsubversion_ptr(NULL))
#undef  PL_sv_placeholder
#define PL_sv_placeholder	(*Perl_Gsv_placeholder_ptr(NULL))
#undef  PL_thr_key
#define PL_thr_key		(*Perl_Gthr_key_ptr(NULL))
#undef  PL_timesbase
#define PL_timesbase		(*Perl_Gtimesbase_ptr(NULL))
#undef  PL_use_safe_putenv
#define PL_use_safe_putenv	(*Perl_Guse_safe_putenv_ptr(NULL))
#undef  PL_version
#define PL_version		(*Perl_Gversion_ptr(NULL))
#undef  PL_veto_cleanup
#define PL_veto_cleanup		(*Perl_Gveto_cleanup_ptr(NULL))
#undef  PL_watch_pvx
#define PL_watch_pvx		(*Perl_Gwatch_pvx_ptr(NULL))

#endif /* !PERL_CORE */
#endif /* MULTIPLICITY && PERL_GLOBAL_STRUCT */

#endif /* __perlapi_h__ */

/* ex: set ro: */
