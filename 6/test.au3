;_IECreate() - Create Internet Explorer Window
;_IEGetObjByName() - Get's a Webpage Name (Similar to Id)
;_IEAction() - Does an Action on an Id / Name or Web Object
;_INetGetSource() - Get's the Webpage's Source
;_IEPropertySet() - Sets a property to an Object - innerText

#include <IE.au3>
#include <Inet.au3>

Local $oIE = _IECreate("http://127.0.0.1/signin")
Local $oSubmit = _IEGetObjByName($oIE, "submitExample")

$Name = _IEGetObjByName($oIE, "email")
$Pass = _IEGetObjByName($oIE, "password")

_IEFormElementSetValue($Name, 'dev.jefferywa@gmail.com')
_IEFormElementSetValue($Pass, 'root')

;_IEAction($oSubmit, "focus")
_IEAction($oSubmit, "click")

WinWait("", "ExampleFormSubmitted")
Sleep(2000)

ControlClick("", "ExampleFormSubmitted", "[CLASS:Button; TEXT:OK; Instance:1;]")
Sleep(2000)


_IEQuit($oIE)
