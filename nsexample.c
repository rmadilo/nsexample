/*
 * The contents of this file are subject to the AOLserver Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://aolserver.com/.
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is AOLserver Code and related documentation
 * distributed by AOL.
 * 
 * The Initial Developer of the Original Code is America Online,
 * Inc. Portions created by AOL are Copyright (C) 1999 America Online,
 * Inc. All Rights Reserved.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License (the "GPL"), in which case the
 * provisions of GPL are applicable instead of those above.  If you wish
 * to allow use of your version of this file only under the terms of the
 * GPL and not to allow others to use your version of this file under the
 * License, indicate your decision by deleting the provisions above and
 * replace them with the notice and other provisions required by the GPL.
 * If you do not delete the provisions above, a recipient may use your
 * version of this file under either the License or the GPL.
 */

/*
 * nsexample.c --
 *
 * A simple AOLserver module example.
 */

static const char *RCSID = "@(#) $Id: nsexample.c,v 1.2 2003/11/01 12:12:48 vasiljevic Exp $, compiled: " __DATE__ " " __TIME__;

/*
 * Always include the AS header file.
 */

#include "ns.h"


/*
 * The Ns_ModuleVersion variable. This allows AOLserver to check 
 * the module init status after having loaded the module.
 */

NS_EXPORT int Ns_ModuleVersion = 1;


/*
 * Each AS module must declare this function. If the module does not 
 * export it, the AS module loader will not load the module.
 */

NS_EXPORT int Ns_ModuleInit(char *hServer, char *hModule);


/*
 * Here you can stuff some private data. This will then be passed as 
 * ClientData to all of your module commands. You can stuff any data
 * here. For illustration purposes, we put only the name of the
 * virtual server and the name of the module.
 */

typedef struct _ExampleContext {
    char *server;
    char *module;
} ExampleContext;


/*
 * -- AS 4.x only --
 *
 * As of AS 4.0, there is a runtime function:
 *    
 *  void Ns_GetVersion(int *major, int *minor, int *serial, int *level)
 *
 * and couple of compile-time macros:
 *
 *  NS_MAJOR_VERSION   - major version
 *  NS_MINOR_VERSION   - minor version
 *  NS_RELEASE_SERIAL  - patch level
 *  NS_RELEASE_LEVEL   - NS_ALPHA_RELEASE, NS_BETA_RELEASE, NS_FINAL_RELEASE
 *
 * for getting server release information. You can use this in your 
 * module if you need to conditionaly compile or load functionality
 * depending on the AS release.
 */


/*
 * Static functions
 */

static Tcl_ObjCmdProc ExampleHelloObjCmd;
static int ExampleInterpInit(Tcl_Interp *interp, void *context);


/*
 *----------------------------------------------------------------------
 *
 * Ns_ModuleInit --
 *
 *      This is the nsexample module's entry point.  AOLserver runs this
 *      function right after the module is loaded.  It is used to read
 *      configuration data, initialize data structures, kick off the Tcl
 *      initialization function (if any), and do other things at startup.
 *
 * Results:
 *	    NS_OK or NS_ERROR
 *
 * Side effects:
 *	    Module loads and initializes itself.
 *
 *----------------------------------------------------------------------
 */
 
int
Ns_ModuleInit(char *hServer, char *hModule)
{
    ExampleContext *context = ns_malloc(sizeof(ExampleContext));

    if (hServer) {
        context->server = ns_malloc(strlen(hServer)+1);
        strcpy(context->server, hServer);
    } else {
        context->server = NULL;
    }
    if (hModule) {
        context->module = ns_malloc(strlen(hModule)+1);
        strcpy(context->module, hModule);
    } else {
        context->module = NULL;
    }

    return Ns_TclInitInterps(hServer, ExampleInterpInit, (void*)context);
}

/*
 *----------------------------------------------------------------------
 *
 * ExampleInterpInit --
 *
 *      Register new commands with the Tcl interpreter.
 *
 * Results:
 *	    NS_OK or NS_ERROR;
 *
 * Side effects:
 *	    A C function is registered with the Tcl interpreter.
 *
 *----------------------------------------------------------------------
 */
 
static int
ExampleInterpInit(Tcl_Interp *interp, void *context)
{
    ClientData clientData = (ClientData)context;

    if (Tcl_CreateObjCommand(interp, "ns_hello", ExampleHelloObjCmd, clientData,
                             (Tcl_CmdDeleteProc*)NULL) == (Tcl_Command)NULL) {
        return NS_ERROR;
    }

    return NS_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * ExampleHelloObjCmd --
 *
 *      A Tcl command that prints a friendly string with the name
 *      passed in on the first argument.
 *
 * Results:
 *	    TCL_OK
 *
 * Side effects:
 *	    Tcl result is set to a string value.
 *
 *----------------------------------------------------------------------
 */
 
static int
ExampleHelloObjCmd(ClientData cd, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[])
{
    ExampleContext *context = (ExampleContext*)cd;
    Tcl_Obj *resObj = Tcl_NewObj();

    Tcl_AppendStringsToObj(resObj, "Hello", NULL);

    if (context->server) {
        Tcl_AppendStringsToObj(resObj, " in server ", context->server, NULL);
    }
    if (context->module) {
        Tcl_AppendStringsToObj(resObj, " from module ", context->module, NULL);
    }

    Tcl_SetObjResult(interp, resObj);

    return TCL_OK;
}

/* EOF $RCSfile: nsexample.c,v $ */
