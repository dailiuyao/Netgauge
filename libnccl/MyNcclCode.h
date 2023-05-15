#ifndef MY_NCCL_CODE_HEADER_FILE_H
#define MY_NCCL_CODE_HEADER_FILE_H

#include <cuda_runtime.h>
#include "nccl.h"

typedef struct {
    ncclComm_t ncclComm;
} MyNcclComm_t;

typedef struct {
    ncclUniqueId ncclId;
} MyncclUniqueId;

typedef ncclDataType_t MyNcclDataType_t;

typedef cudaStream_t MycudaStream_t;

//typedef cudaMemcpyKind MycudaMemcpyKind;

typedef enum {
    MycudaMemcpyHostToHost = 0,
    MycudaMemcpyHostToDevice = 1,
    MycudaMemcpyDeviceToHost = 2,
    MycudaMemcpyDeviceToDevice = 3,
    MycudaMemcpyDefault = 4
} MycudaMemcpyKind;



void MyncclSend(const void* sendbuff, size_t count, MyNcclDataType_t datatype, int peer, MyNcclComm_t mycomm, MycudaStream_t stream);

void MyncclRecv(void* recvbuff, size_t count, MyNcclDataType_t datatype, int peer, MyNcclComm_t mycomm, MycudaStream_t stream);

void MyncclGetUniqueId(MyncclUniqueId Myout);

void MyncclCommInitRank(MyNcclComm_t mycomm, int nranks, MyncclUniqueId Myout, int myrank);

void MycudaStreamCreate (MycudaStream_t* MypStream);

void MycudaStreamDestroy (MycudaStream_t MypStream);

void MyncclCommDestroy (MyNcclComm_t mycomm);

void MycudaMalloc ( void** devPtr, size_t size );

void MycudaFree ( void* devPtr_free );

void MycudaStreamSynchronize ( MycudaStream_t Mystream );

void MycudaMemcpy ( void* dst, const void* src, size_t count, MycudaMemcpyKind kind );

#endif 