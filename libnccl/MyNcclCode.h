#ifndef MY_NCCL_CODE_HEADER_FILE_H
#define MY_NCCL_CODE_HEADER_FILE_H

#include <cuda_runtime.h>
#include "nccl.h"
#include <stdio.h>
#include <stdint.h>  // Provides uint64_t


#ifdef __cplusplus
extern "C" {
#endif

#define CUDACHECK(err) (checkCudaError(err, __FILE__, __LINE__))

static void checkCudaError(cudaError_t err, const char *file, int line)
{
    if (err != cudaSuccess)
    {
        // std::cerr << "CUDA error at " << file << ":" << line << " - " << cudaGetErrorString(err) << std::endl;
        printf("CUDA error at %s:%d - %s\n", file, line, cudaGetErrorString(err));
        exit(-1);
    }
}

#define NCCLCHECK(cmd) do {                         \
  ncclResult_t r = cmd;                             \
  if (r!= ncclSuccess) {                            \
    printf("Failed, NCCL error %s:%d '%s'\n",             \
        __FILE__,__LINE__,ncclGetErrorString(r));   \
    exit(-1);                             \
  }                                                 \
} while(0)

#define MPICHECK(cmd) do {                          \
  int e = cmd;                                      \
  if( e != MPI_SUCCESS ) {                          \
    printf("Failed: MPI error %s:%d '%d'\n",        \
        __FILE__,__LINE__, e);   \
    exit(-1);                             \
  }                                                 \
} while(0)

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

ncclResult_t MyncclSend(const void* sendbuff, size_t count, MyNcclDataType_t datatype, int peer, MyNcclComm_t mycomm, MycudaStream_t stream);

ncclResult_t MyncclRecv(void* recvbuff, size_t count, MyNcclDataType_t datatype, int peer, MyNcclComm_t mycomm, MycudaStream_t stream);

ncclResult_t MyncclGetUniqueId(MyncclUniqueId* Myout);

ncclResult_t MyncclCommInitRank(MyNcclComm_t* mycomm_t, int nranks, MyncclUniqueId Myout, int myrank);

cudaError_t MycudaStreamCreate(MycudaStream_t* MypStream);

cudaError_t MycudaStreamDestroy(MycudaStream_t MypStream);

ncclResult_t MyncclCommDestroy(MyNcclComm_t mycomm);

cudaError_t MycudaMalloc( void** devPtr, size_t size );

cudaError_t MycudaFree( void* devPtr_free );

cudaError_t MycudaStreamSynchronize( MycudaStream_t Mystream );

cudaError_t MycudaMemcpy( void* dst, const void* src, size_t count, MycudaMemcpyKind kind );

uint64_t NCCL_getHostHash(const char* hostname);


#ifdef __cplusplus
}
#endif

#endif 