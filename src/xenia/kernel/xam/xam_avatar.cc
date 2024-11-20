/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2024 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include "xenia/base/logging.h"
#include "xenia/kernel/kernel_state.h"
#include "xenia/kernel/util/shim_utils.h"
#include "xenia/kernel/xam/xam_private.h"
#include "xenia/xbox.h"

namespace xe {
namespace kernel {
namespace xam {

// Start/End
dword_result_t XamAvatarInitialize_entry(
    dword_t unk1,              // 1, 2, 4, etc
    dword_t unk2,              // 0 or 1
    dword_t processor_number,  // for thread creation?
    lpdword_t function_ptrs,   // 20b, 5 pointers
    lpunknown_t unk5,          // ptr in data segment
    dword_t unk6               // flags - 0x00300000, 0x30, etc
) {
  // Negative to fail. Game should immediately call XamAvatarShutdown.
  return X_STATUS_SUCCESS;  //~0u;
}
DECLARE_XAM_EXPORT1(XamAvatarInitialize, kAvatars, kStub);

void XamAvatarShutdown_entry() {
  // Calls XMsgStartIORequestEx(0xf3,0x600002,0,0,0,0).
}
DECLARE_XAM_EXPORT1(XamAvatarShutdown, kAvatars, kStub);

// Get & Set
dword_result_t XamAvatarGetManifestLocalUser_entry(dword_t unk1, dword_t unk2,
                                                   qword_t unk3) {
  // XMsgStartIORequestEx(0xf3, 0x600003, unk3, stack1, 8, 0)

  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGetManifestLocalUser, kAvatars, kStub);

dword_result_t XamAvatarGetManifestsByXuid_entry(dword_t unk1, qword_t unk2,
                                                 qword_t unk3, dword_t unk4,
                                                 dword_t unk5, qword_t unk6) {
  // Function_818D1738(0x600004,param_6,&uStack_d0,0x90,0)

  XELOGD("Stubbed");
  return X_E_ACCESS_DENIED;
}
DECLARE_XAM_EXPORT1(XamAvatarGetManifestsByXuid, kAvatars, kStub)

dword_result_t XamAvatarGetAssetsResultSize_entry(qword_t unk1, qword_t unk2,
                                                  dword_t unk3) {
  // return XMsgInProcessCall(0xf3,0x600005,local_20,0);

  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGetAssetsResultSize, kAvatars, kStub);

dword_result_t XamAvatarGetAssets_entry(qword_t unk1, word_t unk2, dword_t unk3,
                                        dword_t unk4, dword_t unk5,
                                        qword_t unk6) {
  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGetAssets, kAvatars, kStub);

dword_result_t XamAvatarSetCustomAsset_entry(qword_t unk1, qword_t unk2,
                                             dword_t unk3, dword_t unk4,
                                             dword_t unk5, dword_t unk6) {
  // XMsgInProcessCall(0xf3,0x60000a,local_30,0);

  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarSetCustomAsset, kAvatars, kStub)

dword_result_t XamAvatarSetManifest_entry(qword_t unk1, qword_t unk2,
                                          qword_t unk3) {
  // Function_818D1738(0x600009,param_3,&local_410,0x3ec,0);

  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarSetManifest, kAvatars, kStub);

dword_result_t XamAvatarGetMetadataRandom_entry(qword_t unk1, qword_t unk2,
                                                dword_t unk3, qword_t unk4) {
  XELOGD("Stubbed");
  // some_function(0x600010,param_4,local_28,0xc,local_30)
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGetMetadataRandom, kAvatars, kStub);

dword_result_t XamAvatarManifestGetBodyType_entry(qword_t body_type) {
  // return either char of 1 - male, 2 - female, else - unknown
  XELOGD("Stubbed");
  return '\x01';
}
DECLARE_XAM_EXPORT1(XamAvatarManifestGetBodyType, kAvatars, kStub);

dword_result_t XamAvatarGetInstrumentation_entry(qword_t unk1, lpdword_t unk2) {
  return 1;
}
DECLARE_XAM_EXPORT1(XamAvatarGetInstrumentation, kAvatars, kStub);

dword_result_t XamAvatarGetAssetIcon_entry(lpqword_t unk1, dword_t unk2,
                                           dword_t unk3, dword_t unk4,
                                           qword_t unk5) {
  // XMsgStartIORequestEx(0xf3, 0x60000B, unk5, stack1, 0x1C, 0x10000000)

  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGetAssetIcon, kAvatars, kStub);

dword_result_t XamAvatarGetAssetBinary_entry(lpqword_t unk1, dword_t unk2,
                                             dword_t unk3, dword_t unk4,
                                             qword_t unk5) {
  // Function_818D1738(0x600008,param_5,&uStack_60,0x1c,auStack_70);

  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGetAssetBinary, kAvatars, kStub);

dword_result_t XamAvatarGetInstalledAssetPackageDescription_entry(
    qword_t unk1, qword_t unk2) {
  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGetInstalledAssetPackageDescription, kAvatars,
                    kStub);

void XamAvatarSetMocks_entry() {
  // No-op.
}
DECLARE_XAM_EXPORT1(XamAvatarSetMocks, kAvatars, kStub);

// Animation

// https://github.com/xenia-canary/xenia-canary/commit/212c99eee2724de15f471148d10197d89794ff32
dword_result_t XamAvatarLoadAnimation_entry(lpqword_t asset_id_ptr,
                                            dword_t flags, dword_t output,
                                            qword_t unk1) {
  // XMsgStartIORequestEx(0xf3, 0x60000F, unk4, stack1, 0x18, 0x10000000)

  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarLoadAnimation, kAvatars, kStub);

// Enum
dword_result_t XamAvatarBeginEnumAssets_entry(qword_t unk1, qword_t unk2,
                                              dword_t unk3, int_t unk4,
                                              dword_t unk5, qword_t unk6) {
  // XMsgStartIORequestEx(0xf3, 0x60000c, unkn6, stack1, 0x14, stack2)
  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarBeginEnumAssets, kAvatars, kStub);

dword_result_t XamAvatarEnumAssets_entry(dword_t unk1, dword_t unk2,
                                         qword_t unk3) {
  // XMsgStartIORequestEx(0xf3, 0x60000d, unk3, stack1, 8, stack2)

  XELOGD("Stubbed");
  return X_E_NO_MORE_FILES;  // Stop it from calling endlessly
}
DECLARE_XAM_EXPORT1(XamAvatarEnumAssets, kAvatars, kStub);

dword_result_t XamAvatarEndEnumAssets_entry(qword_t unk1) {
  // some_function(0x60000e,param_1,0,0,local_10)

  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarEndEnumAssets, kAvatars, kStub);

// Other
dword_result_t XamAvatarGenerateMipMaps_entry(qword_t unk1, qword_t unk2,
                                              dword_t unk3, dword_t unk4,
                                              qword_t unk5) {
  // Function_818D1738(0x600007,param_5,local_30,0x10,local_40);
  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarGenerateMipMaps, kAvatars, kStub);

dword_result_t XamAvatarWearNow_entry(qword_t unk1, lpdword_t unk2,
                                      qword_t unk3) {
  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarWearNow, kAvatars, kStub);

dword_result_t XamAvatarReinstallAwardedAsset_entry(qword_t unk1, qword_t unk2,
                                                    qword_t unk3) {
  XELOGD("Stubbed");
  return X_STATUS_SUCCESS;
}
DECLARE_XAM_EXPORT1(XamAvatarReinstallAwardedAsset, kAvatars, kStub);

}  // namespace xam
}  // namespace kernel
}  // namespace xe

DECLARE_XAM_EMPTY_REGISTER_EXPORTS(Avatar);
